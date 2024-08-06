#ifndef RESULTS_CONTROLLER_H
#define RESULTS_CONTROLLER_H

#include "../../Ui/results.h"
#include "../../Ui/quizresult.h"
#include "../model/database.h"
#include "../model/quiz.h"

class ResultsController : public QObject
{

Q_OBJECT

public:
    ResultsController(QObject *parent = nullptr);
    void setResultsPage(results *_resultsPage);
    ~ResultsController();

signals:
    void reviewRequest(uint32_t quizId);

public slots:
    void setResults();

private:
    results *resultsPage;
    QVector<quizresult*> quizResultsWidgets;
};



#endif /* RESULTS_CONTROLLER_H */
