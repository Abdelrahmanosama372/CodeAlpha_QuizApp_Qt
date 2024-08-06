#ifndef RESULTS_H
#define RESULTS_H

#include <QWidget>
#include "quizresult.h"

namespace Ui {
class results;
}

class results : public QWidget
{
    Q_OBJECT

public:
    explicit results(QWidget *parent = nullptr);
    void addResultsWidgets(QVector<quizresult*> quizResultWidgets);
    ~results();

private:
    Ui::results *ui;
};

#endif // RESULTS_H
