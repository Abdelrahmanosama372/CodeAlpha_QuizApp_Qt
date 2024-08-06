#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , st(new QStackedWidget)
{
    ui->setupUi(this);
}

void MainWindow::setPages(login *_loginPage, signup *_signupPage, home *_home_page, quizzes *_quizzes_page, quiz *_quizPage, results *_results_page, reviewquiz *_reviewPage, sidebar  *_sidebarWidget)
{
    this->loginPage = _loginPage;
    this->signupPage = _signupPage;
    this->homePage = _home_page;
    this->quizzesPage = _quizzes_page;
    this->quizPage = _quizPage;
    this->resultsPage = _results_page;
    this->reviewPage = _reviewPage;
    this->sidebarWidget = _sidebarWidget;

    this->st->addWidget(loginPage);
    this->st->addWidget(signupPage);
    this->st->addWidget(homePage);
    this->st->addWidget(quizzesPage);
    this->st->addWidget(resultsPage);
    this->st->addWidget(quizPage);
    this->st->addWidget(reviewPage);
    this->sidebarWidget->hide();

    ui->horizontalLayout->addWidget(sidebarWidget);
    ui->horizontalLayout->addWidget(st);
    sidebarWidget->setSidebarPage(SidebarPages::Home);

}

void MainWindow::setupConnections() {
    connect(sidebarWidget, &sidebar::homeButtonClicked, this, &MainWindow::showHomePage);
    connect(sidebarWidget, &sidebar::quizButtonClicked, this, &MainWindow::showQuizzesPage);
    connect(sidebarWidget, &sidebar::resultButtonClicked, this, &MainWindow::showResultsPage);
}

void MainWindow::showSignupPage()
{
    this->st->setCurrentWidget(signupPage);
}

void MainWindow::showHomePage()
{
    this->st->setCurrentWidget(homePage);
    this->sidebarWidget->show();
    sidebarWidget->setSidebarPage(SidebarPages::Home);
}

void MainWindow::showQuizzesPage()
{
    this->st->setCurrentWidget(quizzesPage);
    this->sidebarWidget->show();
    sidebarWidget->setSidebarPage(SidebarPages::Quizzes);
}

void MainWindow::showResultsPage()
{
    this->st->setCurrentWidget(resultsPage);
    this->sidebarWidget->show();
    sidebarWidget->setSidebarPage(SidebarPages::Results);
}

void MainWindow::showQuizPage()
{
    this->st->setCurrentWidget(quizPage);
    this->sidebarWidget->hide();
}

void MainWindow::showReviewPage()
{
    this->st->setCurrentWidget(reviewPage);
    this->sidebarWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
