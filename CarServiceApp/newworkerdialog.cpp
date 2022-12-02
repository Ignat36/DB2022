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

void NewWorkerDialog::on_buttonBox_accepted()
{
    FIO = ui->new_worker_fio_lineEdit->text();
    mail = ui->new_worker_mail_lineEdit->text();
    phone = ui->new_worker_phone_lineEdit->text();

    salary = ui->new_worker_salary_lineEdit->text().toInt();
    Qualification = ui->new_worker_qualification_lineEdit->text();

    this->close();
}

void NewWorkerDialog::on_buttonBox_rejected()
{
    FIO = "";
    this->close();
}
