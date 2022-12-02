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

private:
    Ui::NewWorkerDialog *ui;
};

#endif // NEWWORKERDIALOG_H
