#ifndef QUESTION__H
#define QUESTION__H

#include <QString>
#include <QVector>

namespace quizmodel {
    class Question
    {

    public:
        Question(uint32_t _id, QString _question, QVector<QString> _choices, uint8_t _answer);
        uint32_t getId() const;
        const QString& getQuestionText() const;
        const QVector<QString>& getChoices() const;
        uint8_t getAnswer() const;
        ~Question() = default;
    private:
        uint32_t id;
        QString question;
        QVector<QString> choices;
        uint8_t answer;
    };
}


#endif /* QUESTION__H */
