#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    ui->error_label->hide();
}


login::~login()
{
    delete ui;
}


QString login::getUsername() {
    return ui->username->text();
}

QString login::getPassword() {
    return ui->password->text();
}

void login::on_loginButton_clicked()
{
    emit userLoginRequest();
    ui->username->clear();
    ui->password->clear();
}


void login::on_signupButton_clicked()
{
    emit userSignUpRequest();
}

void login::showError()
{
    ui->error_label->show();
}

