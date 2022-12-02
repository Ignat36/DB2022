#include "newcomponentdialog.h"
#include "ui_newcomponentdialog.h"

NewComponentDialog::NewComponentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewComponentDialog)
{
    ui->setupUi(this);
}

NewComponentDialog::~NewComponentDialog()
{
    delete ui;
}
