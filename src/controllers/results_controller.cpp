#include "../../include/controllers/results_controller.h"

ResultsController::ResultsController(QObject* parent)
{
}

void ResultsController::setResultsPage(results* _resultsPage)
{
  this->resultsPage = _resultsPage;
}

void ResultsController::setResults()
{
    this->quizResultsWidgets.clear();

    quizmodel::Database &db = quizmodel::Database::getDatabase();

    QVector<QPair<quizmodel::Quiz,uint8_t>> quizzesWithScore = db.getResults();

    for(auto &quiz : quizzesWithScore){
        quizresult *result = new quizresult(this->resultsPage);
        result->setResultInfo(quiz.first.getId(), quiz.first.getName(), quiz.first.getQuestionsNumber(), quiz.second);
        connect(result, &quizresult::reviewRequest, this, &ResultsController::reviewRequest);
        this->quizResultsWidgets.push_back(result);
    }

    this->resultsPage->addResultsWidgets(this->quizResultsWidgets);
}

ResultsController::~ResultsController() {
    for (auto resultWidget: qAsConst(this->quizResultsWidgets)) {
        delete resultWidget;
    }
 }
