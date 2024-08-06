#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

signals:
    void userLoginRequest();
    void userSignUpRequest();

public:
    explicit login(QWidget *parent = nullptr);
    QString getUsername();
    QString getPassword();
    void showError();
    ~login();

private slots:
    void on_loginButton_clicked();

    void on_signupButton_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
