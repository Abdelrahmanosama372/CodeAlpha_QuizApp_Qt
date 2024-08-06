#ifndef USER_H
#define USER_H

#include <QString>

namespace quizmodel {
    class User 
    {
        public:
            User(uint32_t _id ,QString _name, uint8_t _totalScore, uint32_t _completedQuizzesNo);
            uint32_t getId() const;
            QString getName() const;
            uint8_t getTotalScore() const;
            uint32_t getCompletedQuizzesNo() const;
            void addOneCompletedQuiz();
            void setTotalScore(uint8_t _totalScore);
        
        private:
            uint32_t id;
            QString name;
            uint8_t totalScore;
            uint32_t completedQuizzesNo;
    };
}

#endif /* USER_H */
