#ifndef NEWDOCUMENTDIALOG_H
#define NEWDOCUMENTDIALOG_H

#include <QDialog>

namespace Ui {
class NewDocumentDialog;
}

class NewDocumentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDocumentDialog(QWidget *parent = nullptr);
    ~NewDocumentDialog();

    QString FIO;
    QString Phone;
    QString Mail;
    QString Brand;
    QString Style;
    QString Model;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NewDocumentDialog *ui;
};

#endif // NEWDOCUMENTDIALOG_H
