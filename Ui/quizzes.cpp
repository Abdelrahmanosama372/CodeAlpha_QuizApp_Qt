#include "quizzes.h"
#include "ui_quizzes.h"

quizzes::quizzes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::quizzes)
{
    ui->setupUi(this);
}

void quizzes::addQuizzesWidgets(const QVector<quizinfo*> &quizInfos)
{
    for(uint32_t i=0; i < ui->quizze_widgets->count(); i++)
    {
        ui->quizze_widgets->removeWidget(ui->quizze_widgets->itemAt(i)->widget());
    }

    for (auto quiz: quizInfos){
        ui->quizze_widgets->addWidget(quiz);
    }
}

quizzes::~quizzes()
{
    delete ui;
}
