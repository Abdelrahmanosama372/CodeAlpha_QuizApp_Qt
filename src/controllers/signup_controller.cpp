#include "../../include/controllers/signup_controller.h"

SignupController::SignupController() {}


void SignupController::setSignupPage(signup *_signupPage) {
    signupPage = _signupPage;
    connect(signupPage, &signup::userSignupRequest, this, &SignupController::validateUserSignup);
}

// todo signup
void SignupController::validateUserSignup() {
    emit userSuccessfulSignup();
}
