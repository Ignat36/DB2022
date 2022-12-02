#include "newcomponentdialog.h"
#include "ui_newcomponentdialog.h"

#include <QString>

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

void NewComponentDialog::on_buttonBox_accepted()
{
    Name = ui->new_component_name_lineEdit->text();
    Price = ui->new_component_price_lineEdit->text().toDouble();
    this->close();
}

void NewComponentDialog::on_buttonBox_rejected()
{
    Name = "";
    Price = -1.0;
    this->close();
}
