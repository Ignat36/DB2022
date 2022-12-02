#ifndef NEWCOMPONENTDIALOG_H
#define NEWCOMPONENTDIALOG_H

#include <QDialog>

namespace Ui {
class NewComponentDialog;
}

class NewComponentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewComponentDialog(QWidget *parent = nullptr);
    ~NewComponentDialog();

    QString Name;
    double Price;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NewComponentDialog *ui;
};

#endif // NEWCOMPONENTDIALOG_H
