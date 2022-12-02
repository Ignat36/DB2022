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

private:
    Ui::NewDocumentDialog *ui;
};

#endif // NEWDOCUMENTDIALOG_H
