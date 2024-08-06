#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include "question.h"

namespace Ui {
class quiz;
}

class quiz : public QWidget
{
    Q_OBJECT

public:
    explicit quiz(QWidget *parent = nullptr);
    void setCurrentQuestions(QVector<question*> _currentQuestions);
    ~quiz();

signals:
    void getNextQuestions(QVector<uint8_t> _userAnswers);

private slots:
    void on_nextButton_clicked();

private:
    QVector<question*> currentQuestions;
    Ui::quiz *ui;
};

#endif // QUIZ_H
