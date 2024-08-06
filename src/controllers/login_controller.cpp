#include "../../include/controllers/login_controller.h"

loginController::loginController(QObject *parent) {

}

void loginController::setLoginPage(login *_loginPage) {
    loginPage = _loginPage;
    connect(loginPage, &login::userLoginRequest, this, &loginController::validateUserLogin);
    connect(loginPage, &login::userSignUpRequest, this, &loginController::userSignupRequest);
}

void loginController::validateUserLogin()
{
    quizmodel::Database &db = quizmodel::Database::getDatabase();
    if(db.validateUserLogin(this->loginPage->getUsername(), this->loginPage->getPassword()))
    {
        emit userSuccessfulLogin();
    }else {
        this->loginPage->showError();
    }

}
