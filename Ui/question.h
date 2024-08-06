#ifndef QUESTION_H
#define QUESTION_H

#include <QWidget>

namespace Ui {
class Question;
}

class question : public QWidget
{
    Q_OBJECT

public:
    explicit question(QWidget *parent = nullptr);
    void setQuestion(const QString &questionText, const QVector<QString> &choices);
    void setQuestion(const QString &questionText, const QVector<QString> &choices, uint8_t answer, uint8_t userChoice);
    uint8_t getUserAnswer();
    ~question();

private:
    Ui::Question *ui;
    void highlightChoice(uint8_t choice,bool isRight);
};

#endif // QUESTION_H
