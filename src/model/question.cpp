#include "../../include/model/question.h"

quizmodel::Question::Question(uint32_t _id, QString _question, QVector<QString> _choices, uint8_t _answer):
    id(_id),
    question(_question),
    choices(_choices),
    answer(_answer)

{
}

uint32_t quizmodel::Question::getId() const
{
    return this->id;
}

const QString& quizmodel::Question::getQuestionText() const
{
    return this->question;
}

const QVector<QString>& quizmodel::Question::getChoices() const
{
    return this->choices;
}

uint8_t quizmodel::Question::getAnswer() const
{
    return this->answer;
}


