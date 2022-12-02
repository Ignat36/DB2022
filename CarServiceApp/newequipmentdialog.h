#ifndef NEWEQUIPMENTDIALOG_H
#define NEWEQUIPMENTDIALOG_H

#include <QDialog>

namespace Ui {
class NewEquipmentDialog;
}

class NewEquipmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewEquipmentDialog(QWidget *parent = nullptr);
    ~NewEquipmentDialog();

    QString Name;
    double Price;
    QString Description;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NewEquipmentDialog *ui;
};

#endif // NEWEQUIPMENTDIALOG_H
