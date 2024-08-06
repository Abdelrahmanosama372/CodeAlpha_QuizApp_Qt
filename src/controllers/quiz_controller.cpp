#include "../../include/controllers/quiz_controller.h"

QuizController::QuizController(QObject *parent):
    currentQuestionIdx(0),
    questionWidgets(2, nullptr)
{ }

void QuizController::setQuizPage(quiz *_quizPage)
{
    this->quizPage = _quizPage;
    connect(this->quizPage, &quiz::getNextQuestions, this, &QuizController::setNextQuestions);
}

void QuizController::startQuiz(uint32_t quizId)
{
    this->currentQuizId = quizId;

    quizmodel::Database &db = quizmodel::Database::getDatabase();
    this->questions = db.getQuizQuestions(quizId);
    this->userAnwers.reserve(this->questions.size());
    this->setQuestionWidgets();
    emit readyToStartQuiz();
}

void QuizController::setNextQuestions(QVector<uint8_t> answers)
{
    for (auto answer: answers){
        this->userAnwers.push_back(answer);
    }
    setQuestionWidgets();
}

void QuizController::setQuestionWidgets()
{
    if(this->currentQuestionIdx >= this->questions.size())
    {
        this->endQuiz();
        emit finishQuiz();
        return;
    }

    delete this->questionWidgets[0];
    delete this->questionWidgets[1];

    question *ques = new question(this->quizPage);
    ques->setQuestion(this->questions[this->currentQuestionIdx].getQuestionText(), this->questions[this->currentQuestionIdx].getChoices());
    this->questionWidgets[0] = ques;

    this->currentQuestionIdx++;

    if(this->currentQuestionIdx < this->questions.size()){
        ques = new question(this->quizPage);
        ques->setQuestion(this->questions[this->currentQuestionIdx].getQuestionText(), this->questions[this->currentQuestionIdx].getChoices());
        this->questionWidgets[1] = ques;
        this->currentQuestionIdx++;
    }


    this->quizPage->setCurrentQuestions(this->questionWidgets);
}

void QuizController::endQuiz()
{
    quizmodel::Database &db = quizmodel::Database::getDatabase();
    db.insertUserAnswers(std::move(this->questions), std::move(this->userAnwers), this->currentQuizId, this->calculateScore());

}

uint8_t QuizController::calculateScore()
{
    uint8_t correctAnswersNo = 0;
    for(uint32_t i=0; i<this->questions.size(); i++)
    {
        if(this->questions[i].getAnswer() == this->userAnwers[i])
        {
            correctAnswersNo++;
        }
    }
    return correctAnswersNo;
}

QuizController::~QuizController()
{
    for (auto widget: qAsConst(this->questionWidgets))
    {
        delete widget;
    }
}



