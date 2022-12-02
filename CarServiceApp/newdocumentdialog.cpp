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
