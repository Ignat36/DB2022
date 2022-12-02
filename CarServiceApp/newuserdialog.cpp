#include "newuserdialog.h"
#include "ui_newuserdialog.h"

NewUserDialog::NewUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewUserDialog)
{
    ui->setupUi(this);

    ui->new_user_role_comboBox->addItem("Админ");
    ui->new_user_role_comboBox->addItem("Менеджер");
    ui->new_user_role_comboBox->addItem("Рабочий");
}

NewUserDialog::~NewUserDialog()
{
    delete ui;
}

void NewUserDialog::on_buttonBox_accepted()
{
    roleid = ui->new_user_role_comboBox->currentIndex() + 1;
    login = ui->new_user_login_lineEdit->text();
    password = ui->new_user_password_lineEdit->text();
    this->close();
}

void NewUserDialog::on_buttonBox_rejected()
{
    login = "";
    this->close();
}
