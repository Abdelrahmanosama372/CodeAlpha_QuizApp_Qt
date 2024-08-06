#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include "sidebar.h"

namespace Ui {
class Home;
}

class home : public QWidget
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    void initPage(QString username, uint32_t completedQuizzes, uint8_t totalSCore);
    void updatePage(uint32_t completedQuizzes, uint8_t totalSCore);
    ~home();

private:
    Ui::Home *ui;
};

#endif // HOME_H
