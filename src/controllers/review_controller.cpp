#include "../../include/controllers/review_controller.h"

ReviewController::ReviewController(QObject* parent)
{ }

void ReviewController::setReviewPage(reviewquiz *_reviewPage)
{
    this->reviewPage = _reviewPage;
    connect(this->reviewPage, &reviewquiz::finishReview, this, &ReviewController::finishReview);
}

void ReviewController::startReview(uint32_t quizId) 
{
    quizmodel::Database &db = quizmodel::Database::getDatabase();

    QVector<quizmodel::Question> quizQuestions = db.getQuizQuestions(quizId);

    QVector<uint8_t> userAnswers = db.getUserQuizAnswers(quizId);
    auto ans_it = userAnswers.begin();

    this->questionWidgets.reserve(quizQuestions.size());

    for(auto &quiz: quizQuestions)
    {
        question *ques = new question(this->reviewPage);
        ques->setQuestion(quiz.getQuestionText(), quiz.getChoices(), quiz.getAnswer(), *ans_it);
        this->questionWidgets.push_back(ques);
        ans_it++;
    }

    this->reviewPage->setCurrentQuestions(this->questionWidgets);
}

void ReviewController::endReview()
{
    for (auto widget: qAsConst(this->questionWidgets)) {
        delete widget;
    }
    this->questionWidgets.clear();
    emit finishReview();
}

ReviewController::~ReviewController() {

}
