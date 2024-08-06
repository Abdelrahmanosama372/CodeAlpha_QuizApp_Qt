#include "quizinfo.h"
#include "ui_quizinfo.h"

quizinfo::quizinfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::quizinfo)
{
    ui->setupUi(this);
}

void quizinfo::setquizInfo(uint32_t _id, QString name, uint8_t questionsNumber)
{
    this->id = _id;
    ui->quiz_name->setText(name);
    ui->questions_number->setText(QString::number(questionsNumber));
}

quizinfo::~quizinfo()
{
    delete ui;
}


void quizinfo::on_start_button_clicked()
{
     emit startQuizRequest(this->id);
}

