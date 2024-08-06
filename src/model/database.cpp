#include "../../include/model/database.h"


quizmodel::Database &quizmodel::Database::getDatabase() {
    static Database db;
    return db;
}

bool quizmodel::Database::initDatabase()
{
    try {
        this->dbConnection = new pqxx::connection (
            "user=postgres password=root_postgres host=127.0.0.1 port=5432 dbname=QuizSystemDB target_session_attrs=read-write");
    } catch (std::exception &e) {
        qDebug("Error accesing the database %s", e.what());
    }


    if(!this->dbConnection->is_open()){
        return false;
    }

    return true;
}

QVector<quizmodel::Quiz> quizmodel::Database::getQuizzes(){

    QVector<quizmodel::Quiz> quizzes;
    pqxx::work W(*this->dbConnection);
    pqxx::result res = W.exec("SELECT * FROM quizzes");

    W.commit();

    for (auto row : res) {
        uint32_t id = row["quiz_id"].as<uint32_t>();
        QString name = QString::fromStdString(row["name"].c_str());
        uint8_t questionsNumber = static_cast<uint8_t>(row["questions_number"].as<uint16_t>());

        quizmodel::Quiz quiz(id, name, questionsNumber);
        quizzes.push_back(quiz);
    }

    return quizzes;
}

QVector<quizmodel::Question> quizmodel::Database::getQuizQuestions(uint32_t quizId)
{
    QVector<quizmodel::Question> questions;
    pqxx::work W(*this->dbConnection);
    pqxx::result res = W.exec("SELECT q.question_id, q.question_text, q.choice1, \
                               q.choice2, q.choice3, q.choice4, q.correct_choice \
                               FROM questions AS q \
                               where quiz_id = " + QString::number(quizId).toStdString() +
                               " ORDER BY q.question_id");

    W.commit();

    for (auto row : res)
    {
        uint32_t id = row["question_id"].as<uint32_t>();
        QString question_text = QString::fromStdString(row["question_text"].c_str());

        QVector<QString> choices(4);
        choices[0] = QString::fromStdString(row["choice1"].c_str());
        choices[1] = QString::fromStdString(row["choice2"].c_str());
        choices[2] = QString::fromStdString(row["choice3"].c_str());
        choices[3] = QString::fromStdString(row["choice4"].c_str());

        uint8_t answer = static_cast<uint8_t>(row["correct_choice"].as<uint16_t>());
        quizmodel::Question question(id,std::move(question_text), std::move(choices), answer);
        questions.push_back(question);
    }

    return questions;
}

QVector<uint8_t> quizmodel::Database::getUserQuizAnswers(uint32_t quizId) {
    QVector<uint8_t> userAnswers;
    pqxx::work W(*this->dbConnection);
    pqxx::result res = W.exec("SELECT a.selected_choice \
                               FROM user_answers as a \
                               WHERE a.quiz_id = " +  QString::number(quizId).toStdString()
                               + " ORDER BY a.question_id");

    W.commit();

    for (auto row : res)
    {
        uint8_t answer = static_cast<uint8_t>(row["selected_choice"].as<uint16_t>());
        userAnswers.push_back(answer);
    }

    return userAnswers;
}

QVector<QPair<quizmodel::Quiz,uint8_t>> quizmodel::Database::getResults()
{
    QVector<QPair<quizmodel::Quiz,uint8_t>> results;
    pqxx::work W(*this->dbConnection);
    pqxx::result res = W.exec("SELECT q.quiz_id, q.name, q.questions_number, u.score \
                              FROM user_quiz_results AS u \
                              INNER JOIN quizzes AS q on q.quiz_id = u.quiz_id \
                              WHERE u.user_id = " + std::to_string(this->currUser->getId()));

    W.commit();

    for (auto row : res) {
        uint32_t id = row["quiz_id"].as<uint32_t>();
        QString name = QString::fromStdString(row["name"].c_str());
        uint8_t questionsNumber = static_cast<uint8_t>(row["questions_number"].as<uint16_t>());
        uint8_t score = static_cast<uint8_t>(row["score"].as<uint16_t>());

        quizmodel::Quiz quiz(id, name, questionsNumber);
        results.push_back(QPair{quiz, score});
    }

    return results;
}

bool quizmodel::Database::validateUserLogin(QString userName, QString password)
{
    pqxx::work W(*this->dbConnection);
    std::hash<std::string> hasher;
    std::string hash = std::to_string(hasher(password.toStdString()));

    pqxx::result res = W.exec_params(
        "SELECT u.user_id, u.username, u.total_score, u.completed_quizzes \
         FROM users u \
         JOIN passwords p ON u.user_id = p.user_id \
         WHERE u.username = $1 AND p.hashed_password = $2",
         userName.toStdString().c_str(), hash.c_str()
    );

    W.commit();

    if(res.empty())
    {
        return false;
    }

    for (auto row : res) {
        uint32_t id = row["user_id"].as<uint32_t>();
        QString userName = QString::fromStdString(row["username"].c_str());
        uint8_t total_score = static_cast<uint8_t>(row["total_score"].as<uint16_t>());
        uint8_t completed_quizzes = static_cast<uint8_t>(row["completed_quizzes"].as<uint16_t>());

        this->currUser = std::make_shared<User>(id, userName, total_score, completed_quizzes);
    }

    return true;
}

void quizmodel::Database::insertUserAnswers(QVector<quizmodel::Question> questions, QVector<uint8_t> answers, uint8_t quizId, uint8_t score)
{
    std::string userIdStr = std::to_string(this->currUser->getId());
    std::string quizIdStr = std::to_string(quizId);

    for(uint32_t i=0;  i < answers.size(); i++)
    {
        pqxx::work W(*this->dbConnection);
        pqxx::result res = W.exec_params("INSERT INTO user_answers (question_id, quiz_id, selected_choice, user_id)\
                                          VALUES ($1, $2, $3, $4)",
                                         std::to_string(questions[i].getId()),
                                         quizIdStr,
                                         std::to_string(answers[i]),
                                         userIdStr);
        W.commit();
    }

    pqxx::work W(*this->dbConnection);
    pqxx::result res = W.exec_params("INSERT INTO user_quiz_results (quiz_id, user_id, score)\
                                     VALUES ($1, $2, $3)",
                                     quizIdStr,
                                     userIdStr,
                                     std::to_string(score));
    W.commit();

    this->updateUserScore();
}

void quizmodel::Database::updateUserScore()
{
    std::string userIdStr = std::to_string(this->currUser->getId());

    pqxx::work W(*this->dbConnection);
    pqxx::result res = W.exec_params("SELECT \
                                     (SELECT COALESCE(SUM(score), 0) \
                                     FROM user_quiz_results \
                                     WHERE user_id = u.user_id) AS total_score, \
                                     (SELECT COALESCE(COUNT(*), 0) \
                                     FROM user_answers \
                                     WHERE user_id = u.user_id) AS total_questions \
                                     FROM users u \
                                     WHERE u.user_id = $1", userIdStr);

    W.commit();


    uint32_t totalScore = res[0]["total_score"].as<uint32_t>();
    uint32_t totalQuestions = res[0]["total_questions"].as<uint32_t>();

    uint8_t newScorePrec = (static_cast<double>(totalScore) / totalQuestions) * 100;

    pqxx::work W2(*this->dbConnection);
    W.exec_params("UPDATE users u \
                  SET total_score = $1 \
                  where u.user_id = $2", std::to_string(newScorePrec), userIdStr);

    this->currUser->setTotalScore(newScorePrec);
    this->currUser->addOneCompletedQuiz();
}

std::shared_ptr<quizmodel::User> quizmodel::Database::getCurrUser() const
{
    return this->currUser;
}

quizmodel::Database::~Database()
{
    delete this->dbConnection;
}
