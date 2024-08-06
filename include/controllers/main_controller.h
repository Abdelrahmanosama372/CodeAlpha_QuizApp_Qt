#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "../../Ui/mainwindow.h"
#include "../../Ui/sidebar.h"
#include "login_controller.h"
#include "signup_controller.h"
#include "quizzes_controller.h"
#include "quiz_controller.h"
#include "results_controller.h"
#include "review_controller.h"
#include "home_controller.h"

class MainController : public QObject
{

Q_OBJECT

public:
    MainController(MainWindow *_mainWindow, loginController *_logincontroller, SignupController *_signupController,
                   QuizzesController *_quizzescontroller, QuizController *_quizcontroller, ResultsController *_resultsController,
                   ReviewController *_reviewController, HomeController *_homeController,sidebar *_sidebarWidget);

private:
    MainWindow *mainWindow;
    loginController *logincontroller;
    SignupController *signupController;
    sidebar *sidebarWidget;
    QuizzesController *quizzescontroller;
    QuizController *quizcontroller;
    ResultsController *resultsController;
    ReviewController *reviewController;
    HomeController *homeController;
    void setupConnections();
};

#endif // MAINCONTROLLER_H
