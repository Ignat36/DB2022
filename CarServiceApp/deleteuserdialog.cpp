#include "deleteuserdialog.h"
#include "ui_deleteuserdialog.h"

DeleteUserDialog::DeleteUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteUserDialog)
{
    ui->setupUi(this);
}

DeleteUserDialog::~DeleteUserDialog()
{
    delete ui;
}

void DeleteUserDialog::on_buttonBox_accepted()
{
    login = ui->delete_user_login_lineEdit->text();
    password = ui->selete_user_password_lineEdit->text();
    this->close();
}

void DeleteUserDialog::on_buttonBox_rejected()
{
    login = "";
    password = "";
    this->close();
}
