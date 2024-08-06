#ifndef QUIZZES_H
#define QUIZZES_H

#include <QWidget>
#include <QVector>
#include "quizinfo.h"
#include "../include/model/quiz.h"

namespace Ui {
class quizzes;
}

namespace quizmodel {
class Quiz;
}

class quizzes : public QWidget
{
    Q_OBJECT

public:
    explicit quizzes(QWidget *parent = nullptr);
    void addQuizzesWidgets(const QVector<quizinfo*> & quizInfos);
    ~quizzes();

private:
    Ui::quizzes *ui;
};

#endif // QUIZZES_H
