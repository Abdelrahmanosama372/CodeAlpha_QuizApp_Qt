#include "../../include/controllers/home_controller.h"

void HomeController::setHomePage(home *_homePage)
{
    this->homePage = _homePage;
}

void HomeController::initHomePage()
{
    quizmodel::Database &db = quizmodel::Database::getDatabase();
    std::shared_ptr<quizmodel::User> user = db.getCurrUser();
    this->homePage->initPage(user->getName() ,user->getCompletedQuizzesNo(), user->getTotalScore());
}

void HomeController::updateHomePage()
{
    quizmodel::Database &db = quizmodel::Database::getDatabase();
    std::shared_ptr<quizmodel::User> user = db.getCurrUser();
    this->homePage->updatePage(user->getCompletedQuizzesNo(), user->getTotalScore());
}
