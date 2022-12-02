#include "newworkerdialog.h"
#include "ui_newworkerdialog.h"

NewWorkerDialog::NewWorkerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewWorkerDialog)
{
    ui->setupUi(this);
}

NewWorkerDialog::~NewWorkerDialog()
{
    delete ui;
}
