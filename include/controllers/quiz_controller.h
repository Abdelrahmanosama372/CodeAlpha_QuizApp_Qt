#ifndef QUIZ_CONTROLLER_H
#define QUIZ_CONTROLLER_H

#include "../../Ui/quiz.h"
#include "../model/database.h"
#include "../model/question.h"
#include "../../Ui/question.h"



class QuizController : public QObject
{

Q_OBJECT

public:
    QuizController(QObject *parent = nullptr);
    void setQuizPage(quiz *_quizPage);
    ~QuizController();

signals:
    void finishQuiz();
    void readyToStartQuiz();

public slots:
    void startQuiz(uint32_t quizId);
    void setNextQuestions(QVector<uint8_t> answers);
    
private:
    quiz *quizPage;
    QVector<uint8_t> userAnwers;
    QVector<quizmodel::Question> questions;
    QVector<question*> questionWidgets;
    uint32_t currentQuestionIdx;
    uint32_t currentQuizId;
    void setQuestionWidgets();
    void endQuiz();
    uint8_t calculateScore();
};



#endif /* QUIZ_CONTROLLER_H */
