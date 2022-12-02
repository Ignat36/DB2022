#ifndef NEWWORKERDIALOG_H
#define NEWWORKERDIALOG_H

#include <QDialog>

namespace Ui {
class NewWorkerDialog;
}

class NewWorkerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewWorkerDialog(QWidget *parent = nullptr);
    ~NewWorkerDialog();

    QString FIO;
    QString mail;
    QString phone;
    QString Qualification;
    double salary;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NewWorkerDialog *ui;
};

#endif // NEWWORKERDIALOG_H
