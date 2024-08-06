#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>

enum class SidebarPages {
    Home,
    Quizzes,
    Results,
};

namespace Ui {
class SideBar;
}

class sidebar : public QWidget
{
    Q_OBJECT

public:
    explicit sidebar(QWidget *parent = nullptr);
    void setSidebarPage(SidebarPages page);
    ~sidebar();

signals:
    void homeButtonClicked();
    void quizButtonClicked();
    void resultButtonClicked();

private slots:
    void on_quit_extend_button_clicked();

    void on_quit_compact_button_clicked();

    void on_home_extend_button_clicked();

    void on_quizes_extend_button_clicked();

    void on_results_extend_button_clicked();

    void on_home_compact_button_clicked();

    void on_quizes_compact_button_clicked();

    void on_results_compact_button_clicked();

private:
    void clearPages();
    Ui::SideBar *ui;
};

#endif // SIDEBAR_H
