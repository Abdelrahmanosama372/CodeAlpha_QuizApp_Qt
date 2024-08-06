#ifndef QUIZZES_CONTROLLER_H
#define QUIZZES_CONTROLLER_H

#include "../../Ui/quizzes.h"
#include "../model/database.h"
#include "../model/quiz.h"

class QuizzesController : public QObject
{

Q_OBJECT

public:
    QuizzesController(QObject *parent = nullptr);
    void setQuizzesPage(quizzes *_quizPage);
    ~QuizzesController();

signals:
    void startQuizRequest(uint32_t quizId);

public slots:
    void getQuizzes();
private:
    quizzes *quizPage;
    QVector<quizinfo*> quizInfos; 
    void addQuizzes(QVector<quizinfo*> quizInfos);
};



#endif /* QUIZZES_CONTROLLER_H */
