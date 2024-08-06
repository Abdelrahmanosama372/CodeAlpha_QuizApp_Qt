#include "sidebar.h"
#include "ui_sidebar.h"

sidebar::sidebar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SideBar)
{
    ui->setupUi(this);
    ui->list_combact->hide();
}

sidebar::~sidebar()
{
    delete ui;
}

void sidebar::setSidebarPage(SidebarPages page)
{
    this->clearPages();

    switch (page) {
    case SidebarPages::Home:
        ui->home_extend_button->setChecked(true);
        ui->home_compact_button->setChecked(true);
        break;
    case SidebarPages::Quizzes:
        ui->quizes_extend_button->setChecked(true);
        ui->quizes_compact_button->setChecked(true);
        break;
    case SidebarPages::Results:
        ui->results_extend_button->setChecked(true);
        ui->results_compact_button->setChecked(true);
        break;
    }
}

void sidebar::clearPages()
{
    ui->home_extend_button->setChecked(false);
    ui->home_compact_button->setChecked(false);

    ui->quizes_extend_button->setChecked(false);
    ui->quizes_compact_button->setChecked(false);

    ui->results_extend_button->setChecked(false);
    ui->results_compact_button->setChecked(false);
}

void sidebar::on_quit_extend_button_clicked()
{
    QCoreApplication::exit(0);
}

void sidebar::on_quit_compact_button_clicked()
{
    sidebar::on_quit_extend_button_clicked();
}

void sidebar::on_home_extend_button_clicked()
{
    ui->home_extend_button->setChecked(true);
    ui->home_compact_button->setChecked(true);

    ui->results_extend_button->setChecked(false);
    ui->results_compact_button->setChecked(false);
    ui->quizes_extend_button->setChecked(false);
    ui->quizes_compact_button->setChecked(false);

    emit homeButtonClicked();
}


void sidebar::on_quizes_extend_button_clicked()
{

    ui->quizes_extend_button->setChecked(true);
    ui->quizes_compact_button->setChecked(true);

    ui->results_extend_button->setChecked(false);
    ui->results_compact_button->setChecked(false);
    ui->home_extend_button->setChecked(false);
    ui->home_compact_button->setChecked(false);

    emit quizButtonClicked();

}


void sidebar::on_results_extend_button_clicked()
{
    ui->results_extend_button->setChecked(true);
    ui->results_compact_button->setChecked(true);

    ui->quizes_extend_button->setChecked(false);
    ui->quizes_compact_button->setChecked(false);
    ui->home_extend_button->setChecked(false);
    ui->home_compact_button->setChecked(false);

    emit resultButtonClicked();
}


void sidebar::on_home_compact_button_clicked()
{
    sidebar::on_home_extend_button_clicked();
}


void sidebar::on_quizes_compact_button_clicked()
{
    sidebar::on_quizes_extend_button_clicked();
}


void sidebar::on_results_compact_button_clicked()
{
    sidebar::on_results_extend_button_clicked();
}


