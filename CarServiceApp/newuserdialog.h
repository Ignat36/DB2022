#ifndef NEWUSERDIALOG_H
#define NEWUSERDIALOG_H

#include <QDialog>

namespace Ui {
class NewUserDialog;
}

class NewUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewUserDialog(QWidget *parent = nullptr);
    ~NewUserDialog();

private:
    Ui::NewUserDialog *ui;
};

#endif // NEWUSERDIALOG_H
