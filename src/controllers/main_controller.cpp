#include "../../include/controllers/main_controller.h"

MainController::MainController(MainWindow *_mainWindow, loginController *_logincontroller, SignupController *_signupController,
                               QuizzesController *_quizzescontroller, QuizController *_quizcontroller, ResultsController *_resultsController,
                               ReviewController *_reviewController, HomeController *_homeController, sidebar *_sidebarWidget):
    mainWindow(_mainWindow),
    logincontroller(_logincontroller),
    signupController(_signupController),
    quizzescontroller(_quizzescontroller),
    sidebarWidget(_sidebarWidget),
    quizcontroller(_quizcontroller),
    resultsController(_resultsController),
    reviewController(_reviewController),
    homeController(_homeController)
{
    this->setupConnections();
}

void MainController::setupConnections()
{
    connect(logincontroller, &loginController::userSuccessfulLogin, mainWindow, &MainWindow::showHomePage);
    connect(logincontroller, &loginController::userSignupRequest, mainWindow, &MainWindow::showSignupPage);
    connect(signupController, &SignupController::userSuccessfulSignup, mainWindow, &MainWindow::showHomePage);
    connect(sidebarWidget, &sidebar::quizButtonClicked, quizzescontroller, &QuizzesController::getQuizzes);
    connect(quizzescontroller, &QuizzesController::startQuizRequest, quizcontroller, &QuizController::startQuiz);
    connect(quizcontroller, &QuizController::readyToStartQuiz, mainWindow, &MainWindow::showQuizPage);
    connect(quizcontroller, &QuizController::finishQuiz, mainWindow, &MainWindow::showResultsPage);
    connect(quizcontroller, &QuizController::finishQuiz, resultsController, &ResultsController::setResults);
    connect(resultsController, &ResultsController::reviewRequest, reviewController, &ReviewController::startReview);
    connect(resultsController, &ResultsController::reviewRequest, mainWindow, &MainWindow::showReviewPage);
    connect(reviewController, &ReviewController::finishReview, mainWindow, &MainWindow::showResultsPage);
    connect(sidebarWidget, &sidebar::resultButtonClicked, resultsController, &ResultsController::setResults);
    connect(logincontroller, &loginController::userSuccessfulLogin, homeController, &HomeController::initHomePage);
    connect(quizcontroller, &QuizController::finishQuiz, homeController, &HomeController::updateHomePage);
}
