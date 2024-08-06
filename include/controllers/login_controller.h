#ifndef LOGINCONTROLLER_HPP
#define LOGINCONTROLLER_HPP

#include "../../Ui/login.h"
#include "../model/database.h"

class loginController : public QObject
{
Q_OBJECT

private slots:
    void validateUserLogin();

signals:
    void userSuccessfulLogin();
    void userSignupRequest();
public:
    explicit loginController(QObject *parent = nullptr);
    void setLoginPage(login *_loginPage);

private:
    login *loginPage;
};

#endif // LOGINCONTROLLER_HPP
