#ifndef QUIZINFO_H
#define QUIZINFO_H

#include <QWidget>

namespace Ui {
class quizinfo;
}

class quizinfo : public QWidget
{
    Q_OBJECT

public:
    explicit quizinfo(QWidget *parent = nullptr);

    void setquizInfo(uint32_t _id, QString name, uint8_t questionsNumber);
    ~quizinfo();

signals:
    void startQuizRequest(uint32_t quizId);

private slots:
    void on_start_button_clicked();

private:
    uint32_t id;
    Ui::quizinfo *ui;
};

#endif // QUIZINFO_H
