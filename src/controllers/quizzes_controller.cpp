#include "../../include/controllers/quizzes_controller.h"

QuizzesController::QuizzesController(QObject* parent)
{
}

void QuizzesController::setQuizzesPage(quizzes* _quizPage)
{
  this->quizPage = _quizPage;
}

void QuizzesController::getQuizzes()
{
    if(!this->quizInfos.isEmpty())
    {
        return;
    }

    quizmodel::Database &db = quizmodel::Database::getDatabase();
    QVector<quizmodel::Quiz> quizzes = db.getQuizzes();

    for(auto &quiz : quizzes){
        quizinfo *info = new quizinfo(this->quizPage);
        info->setquizInfo(quiz.getId(), quiz.getName(), quiz.getQuestionsNumber());
        connect(info, &quizinfo::startQuizRequest, this, &QuizzesController::startQuizRequest);
        this->quizInfos.push_back(info);
    }

    quizPage->addQuizzesWidgets(this->quizInfos);
}

QuizzesController::~QuizzesController() {
    for (auto quiz: qAsConst(this->quizInfos)) {
        delete quiz;
    }
 }
