#ifndef SIGNUPCONTROLLER_H
#define SIGNUPCONTROLLER_H

#include <QObject>
#include "../../Ui/signup.h"

class SignupController : public QObject
{
    Q_OBJECT
public:
    SignupController();
    void setSignupPage(signup *_signupPage);

signals:
    void userSuccessfulSignup();
private:
    signup *signupPage;
    void validateUserSignup();
};

#endif // SIGNUPCONTROLLER_H
