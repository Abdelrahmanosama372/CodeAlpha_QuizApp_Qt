#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "home.h"
#include "sidebar.h"
#include "quiz.h"
#include "signup.h"
#include "quizzes.h"
#include "reviewquiz.h"
#include "results.h"
#include "sidebar.h"
#include "login.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setPages(login *_loginPage, signup *_signupPage, home *_home_page, quizzes *_quizzes_page, quiz *_quizPage, results *_results_page, reviewquiz *_reviewPage, sidebar  *_sidebarWidget);
    void setupConnections();
    ~MainWindow();


public slots:
    void showSignupPage();
    void showHomePage();
    void showQuizzesPage();
    void showQuizPage();
    void showResultsPage();
    void showReviewPage();

private:
    Ui::MainWindow *ui;
    QStackedWidget *st;
    home *homePage;
    quizzes *quizzesPage;
    results *resultsPage;
    login *loginPage;
    signup *signupPage;
    quiz *quizPage;
    reviewquiz *reviewPage;
    sidebar *sidebarWidget;
};
#endif // MAINWINDOW_H
