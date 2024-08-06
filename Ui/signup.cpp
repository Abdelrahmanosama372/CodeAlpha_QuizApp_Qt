#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
    emit userSignupRequest();
}

