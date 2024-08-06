#include "mainwindow.h"
#include "login.h"
#include "signup.h"
#include "home.h"
#include "quizzes.h"
#include "reviewquiz.h"
#include "results.h"
#include "quiz.h"
#include "../include/controllers/main_controller.h"
#include "../include/controllers/login_controller.h"
#include "../include/controllers/quizzes_controller.h"
#include "../include/controllers/signup_controller.h"
#include "../include/controllers/quiz_controller.h"
#include "../include/controllers/home_controller.h"
#include "../include/model/database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    quizmodel::Database &db = quizmodel::Database::getDatabase();
    if(db.initDatabase() == false)
    {
        QCoreApplication::quit();
    }

    MainWindow w;

    sidebar sidbarWidget(&w);
    login loginPage(&w);
    signup signupPage(&w);
    home homePage(&w);
    quizzes quizzesPage(&w);
    results resultsPage(&w);
    quiz quizPage(&w);
    reviewquiz reviewPage(&w);

    loginController lc;
    lc.setLoginPage(&loginPage);

    SignupController sc;
    sc.setSignupPage(&signupPage);

    QuizzesController qzc;
    qzc.setQuizzesPage(&quizzesPage);

    QuizController qc;
    qc.setQuizPage(&quizPage);

    ResultsController rc;
    rc.setResultsPage(&resultsPage);

    ReviewController rec;
    rec.setReviewPage(&reviewPage);

    HomeController hc;
    hc.setHomePage(&homePage);

    MainController mc(&w, &lc, &sc, &qzc, &qc, &rc, &rec, &hc, &sidbarWidget);

    w.setPages(&loginPage, &signupPage, &homePage, &quizzesPage, &quizPage, &resultsPage, &reviewPage, &sidbarWidget);
    w.setupConnections();
    w.show();
    return a.exec();
}
