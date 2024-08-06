#ifndef QUIZ__H
#define QUIZ__H

#include "QString"

namespace quizmodel {
    class Quiz
    {
    public:
        Quiz(uint32_t _id, QString _name, uint8_t _questionsNumber);
        uint32_t getId() const;
        QString getName() const;
        uint8_t getQuestionsNumber() const;

    private:
        uint32_t id;
        QString name;
        uint8_t questionsNumber;
    };
}

#endif // QUIZ__H
