#ifndef DATABASE_H
#define DATABASE_H

#include <QVector>
#include "quiz.h"
#include "question.h"
#include "user.h"
#include <pqxx/pqxx>
#include <functional>

namespace quizmodel {
    class Database
    {

    public:
        static Database &getDatabase();
        bool initDatabase();
        QVector<quizmodel::Quiz> getQuizzes();
        QVector<quizmodel::Question> getQuizQuestions(uint32_t quizId);
        QVector<uint8_t> getUserQuizAnswers(uint32_t quizId);
        QVector<QPair<quizmodel::Quiz,uint8_t>> getResults();
        bool validateUserLogin(QString userName, QString password);
        void insertUserAnswers(QVector<Question> questions, QVector<uint8_t> answers, uint8_t quizId, uint8_t score);
        std::shared_ptr<User> getCurrUser() const;
        ~Database();

    private:
        Database() = default;
        std::shared_ptr<User> currUser ;
        pqxx::connection *dbConnection;
        void updateUserScore();
    };
}



#endif /* DATABASE_H */
