#include "quiz.h"
#include "ui_quiz.h"


quiz::quiz(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::quiz)
{
    ui->setupUi(this);
}

void quiz::setCurrentQuestions(QVector<question*> _currentQuestions)
{
    this->currentQuestions = _currentQuestions;

    for(auto widget: qAsConst(this->currentQuestions))
    {
        ui->questionsLayout->addWidget(widget);
    }
}

void quiz::on_nextButton_clicked()
{
    QVector<uint8_t> userAnswers;
    userAnswers.reserve(this->currentQuestions.size());

    for(auto question: qAsConst(this->currentQuestions))
    {
        userAnswers.push_back(question->getUserAnswer());
    }
    emit getNextQuestions(userAnswers);
}


quiz::~quiz()
{
    delete ui;
}
