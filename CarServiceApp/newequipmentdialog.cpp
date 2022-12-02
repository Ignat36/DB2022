#include "newequipmentdialog.h"
#include "ui_newequipmentdialog.h"

NewEquipmentDialog::NewEquipmentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEquipmentDialog)
{
    ui->setupUi(this);
}

NewEquipmentDialog::~NewEquipmentDialog()
{
    delete ui;
}

void NewEquipmentDialog::on_buttonBox_accepted()
{
    Name = ui->new_equipmentt_name_lineEdit->text();
    Price = ui->new_equipment_price_lineEdit->text().toDouble();
    Description = ui->new_equipment_description_lineEdit->text();
    this->close();
}

void NewEquipmentDialog::on_buttonBox_rejected()
{
    Name = "";
    this->close();
}
