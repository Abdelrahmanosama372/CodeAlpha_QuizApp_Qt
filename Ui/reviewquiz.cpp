#include "reviewquiz.h"
#include "ui_reviewquiz.h"

reviewquiz::reviewquiz(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::reviewquiz)
{
    ui->setupUi(this);
}

void reviewquiz::setCurrentQuestions(QVector<question*> questionWidgets)
{
    for(auto widget: qAsConst(questionWidgets))
    {
        ui->questions_layout->addWidget(widget);
    }
}

reviewquiz::~reviewquiz()
{
    delete ui;
}



void reviewquiz::on_finishButton_clicked()
{
    emit finishReview();
}

