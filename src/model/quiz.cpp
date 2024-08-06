#include "../../include/model/quiz.h"

quizmodel::Quiz::Quiz(uint32_t _id, QString _name, uint8_t _questionsNumber):
    id(_id),
    name(std::move(_name)),
    questionsNumber(_questionsNumber)
{

}

uint32_t quizmodel::Quiz::getId() const
{
    return this->id;
}

QString quizmodel::Quiz::getName() const
{
    return this->name;
}

uint8_t quizmodel::Quiz::getQuestionsNumber() const
{
    return this->questionsNumber;
}
