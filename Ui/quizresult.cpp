#include "quizresult.h"
#include "ui_quizresult.h"

quizresult::quizresult(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::quizresult)
{
    ui->setupUi(this);
}

void quizresult::setResultInfo(uint32_t quizId, QString quizName, uint8_t questionsNumber, uint8_t quizScore)
{
    this->quizId = quizId;
    ui->quiz_name->setText(quizName);
    ui->score->setText(QString::number(quizScore)+"/"+QString::number(questionsNumber));
}


quizresult::~quizresult()
{
    delete ui;
}

void quizresult::on_review_button_clicked()
{
    emit reviewRequest(this->quizId);
}

