#include "home.h"
#include "ui_home.h"

home::home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
}

void home::initPage(QString username, uint32_t completedQuizzes, uint8_t totalSCore)
{
    ui->username->setText(username);
    updatePage(completedQuizzes, totalSCore);
}

void home::updatePage(uint32_t completedQuizzes, uint8_t totalSCore)
{
    ui->totalScorePB->setValue(totalSCore);
    ui->completedQuizzesNo->setText(QString::number(completedQuizzes));
}

home::~home()
{
    delete ui;
}
