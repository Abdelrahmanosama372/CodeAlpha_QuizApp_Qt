#ifndef QUIZRESULT_H
#define QUIZRESULT_H

#include <QWidget>

namespace Ui {
class quizresult;
}

class quizresult : public QWidget
{
    Q_OBJECT

public:
    explicit quizresult(QWidget *parent = nullptr);
    void setResultInfo(uint32_t quizId, QString quizName, uint8_t questionsNumber, uint8_t quizScore);
    ~quizresult();

signals:
    void reviewRequest(uint32_t quizId);

private slots:
    void on_review_button_clicked();

private:
    uint32_t quizId;
    Ui::quizresult *ui;
};

#endif // QUIZRESULT_H
