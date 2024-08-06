#include "../../include/model/user.h"

quizmodel::User::User(uint32_t _id ,QString _name, uint8_t _totalScore, uint32_t _completedQuizzesNo):
    id(_id),
    name(_name),
    totalScore(_totalScore),
    completedQuizzesNo(_completedQuizzesNo)
{ }

uint32_t quizmodel::User::getId() const
{
    return this->id;
}

QString quizmodel::User::getName() const
{
    return this->name;
}

uint8_t quizmodel::User::getTotalScore() const
{
    return this->totalScore;
}

uint32_t quizmodel::User::getCompletedQuizzesNo() const
{
    return this->completedQuizzesNo;
}

void quizmodel::User::setTotalScore(uint8_t _totalScore)
{
    this->totalScore = _totalScore;
}

void quizmodel::User::addOneCompletedQuiz()
{
    this->completedQuizzesNo++;
}
