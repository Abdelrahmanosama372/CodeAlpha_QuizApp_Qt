#include "results.h"
#include "ui_results.h"

results::results(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::results)
{
    ui->setupUi(this);
}

void results::addResultsWidgets(QVector<quizresult*> quizResultWidgets)
{
    while (QLayoutItem *item = ui->results_layout->takeAt(0)) {
        if (QWidget *widget = item->widget()) {
            ui->results_layout->removeWidget(widget);
        }
    }

    for(auto widget: qAsConst(quizResultWidgets))
    {
        ui->results_layout->addWidget(widget);
    }
}

results::~results()
{
    delete ui;
}
