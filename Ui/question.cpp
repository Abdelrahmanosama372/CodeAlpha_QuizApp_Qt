#include "question.h"
#include "ui_question.h"

question::question(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Question)
{
    ui->setupUi(this);
}

void question::setQuestion(const QString &questionText, const QVector<QString> &choices)
{
    ui->question_text->setText(questionText);

    ui->choice1->setText(choices[0]);
    ui->choice2->setText(choices[1]);
    ui->choice3->setText(choices[2]);
    ui->choice4->setText(choices[3]);
}

void question::setQuestion(const QString &questionText, const QVector<QString> &choices, uint8_t answer, uint8_t userChoice)
{
    setQuestion(questionText, choices);

    highlightChoice(answer, true);

    if(userChoice != answer)
    {
        highlightChoice(userChoice, false);
    }

}

uint8_t question::getUserAnswer()
{
    if(ui->choice1->isChecked())
        return 1;
    else if(ui->choice2->isChecked())
        return 2;
    else if(ui->choice3->isChecked())
        return 3;
    else if(ui->choice4->isChecked())
        return 4;
    return 250; // todo handle error
}

void question::highlightChoice(uint8_t choice,bool isRight)
{
    QString highlightStyle;
    if (isRight){
        highlightStyle = "background: green; border-radius: 5px;";
    }else {
        highlightStyle = "background: red; border-radius: 5px;";
    }

    switch (choice) {
    case 1:
        ui->choice1->setStyleSheet(highlightStyle);
        break;
    case 2:
        ui->choice2->setStyleSheet(highlightStyle);
        break;

    case 3:
        ui->choice3->setStyleSheet(highlightStyle);
        break;

    case 4:
        ui->choice4->setStyleSheet(highlightStyle);
        break;
    }
}

question::~question()
{
    delete ui;
}
