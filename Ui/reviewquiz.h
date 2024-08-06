#ifndef REVIEWQUIZ_H
#define REVIEWQUIZ_H

#include <QWidget>
#include "question.h"

namespace Ui {
class reviewquiz;
}

class reviewquiz : public QWidget
{
    Q_OBJECT

public:
    explicit reviewquiz(QWidget *parent = nullptr);
    void setCurrentQuestions(QVector<question*> questionWidgets);
    ~reviewquiz();

signals:
    void finishReview();


private slots:
    void on_finishButton_clicked();

private:
    Ui::reviewquiz *ui;
};

#endif // REVIEWQUIZ_H
