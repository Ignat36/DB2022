#include "newdocumentdialog.h"
#include "ui_newdocumentdialog.h"

NewDocumentDialog::NewDocumentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDocumentDialog)
{
    ui->setupUi(this);
}

NewDocumentDialog::~NewDocumentDialog()
{
    delete ui;
}

void NewDocumentDialog::on_buttonBox_accepted()
{
    FIO = ui->new_document_fio_lineEdit->text();
    Phone = ui->new_document_phone_lineEdit->text();
    Mail = ui->new_document_mail_lineEdit->text();

    Brand = ui->new_document_brand_lineEdit->text();
    Model = ui->new_document_model_lineEdit->text();
    Style = ui->new_document_bodystyle_lineEdit->text();

    this->close();
}

void NewDocumentDialog::on_buttonBox_rejected()
{
    FIO = "";
    this->close();
}
