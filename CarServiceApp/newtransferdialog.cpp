#include "newtransferdialog.h"
#include "ui_newtransferdialog.h"

NewTransferDialog::NewTransferDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTransferDialog)
{
    ui->setupUi(this);

    ui->type_comboBox->addItem("Оплата работ");
    ui->type_comboBox->addItem("Зарплата работникам");

    ui->type_comboBox->setEditable(true);
    ui->type_comboBox->lineEdit()->setReadOnly(true);
    ui->type_comboBox->lineEdit()->setAlignment(Qt::AlignCenter);

    for (int i = 0 ; i < ui->type_comboBox->count() ; ++i) {
        ui->type_comboBox->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
}

NewTransferDialog::~NewTransferDialog()
{
    delete ui;
}

void NewTransferDialog::on_buttonBox_accepted()
{
    type = ui->type_comboBox->currentIndex() ? "Worker" : "Client";
    cash = ui->cash_lineEdit->text().toInt();
    cardNumber= ui->account_number_lineEdit->text();
    this->close();
}

void NewTransferDialog::on_buttonBox_rejected()
{
    type = "";
    this->close();
}
