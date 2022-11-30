#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(resetWarning()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SignIn_button_clicked()
{
    QString login = ui->LoginEnter->text();
    QString password = ui->PasswordEnter->text();

    try {
        User user = dao.GetUser(login, password);
        ui->stackedWidget->setCurrentIndex(1);
    } catch (std::runtime_error e) {
        setWarning(e.what());
        return;
    }
}

void MainWindow::on_workers_search_button_clicked()
{

}

void MainWindow::resetWarning()
{
    ui->warning_message_label->setText("");
    timer->stop();
}

void MainWindow::setWarning(const QString &message, int time)
{
    ui->warning_message_label->setText(" * " + message + " * ");
    timer->stop();
    timer->start(time * 1000);
}
