#ifndef REVIEW_CONTROLLER_H
#define REVIEW_CONTROLLER_H

#include "../../Ui/reviewquiz.h"
#include "../../Ui/question.h"
#include "../model/database.h"
#include "../model/question.h"

class ReviewController : public QObject
{

Q_OBJECT

public:
    ReviewController(QObject *parent = nullptr);
    void setReviewPage(reviewquiz *_reviewPage);
    ~ReviewController();

signals:
    void finishReview();

public slots:
    void startReview(uint32_t quizId);
    void endReview();

private:
    reviewquiz *reviewPage;
    QVector<question*> questionWidgets;
};



#endif /* REVIEW_CONTROLLER_H */
