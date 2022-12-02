#ifndef NEWTRANSFERDIALOG_H
#define NEWTRANSFERDIALOG_H

#include <QDialog>

namespace Ui {
class NewTransferDialog;
}

class NewTransferDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTransferDialog(QWidget *parent = nullptr);
    ~NewTransferDialog();

    QString type;
    double cash;
    QString cardNumber;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NewTransferDialog *ui;
};

#endif // NEWTRANSFERDIALOG_H
