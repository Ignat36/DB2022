#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "databasecarservicedao.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setDisplaiedText(std::vector<QString> strings);
    void setDisplaiedText(const QString& string);
    void BindComboBox();

private slots:
    void resetWarning();

    void on_SignIn_button_clicked();

    void on_workers_search_button_clicked();

    void on_client_search_button_clicked();

    void on_workingequipment_button_clicked();

    void on_components_button_clicked();

    void on_exit_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer = new QTimer();

    DataBaseCarServiceDAO dao;

private:

    void setWarning(const QString& warning, int time = 5);
    QString serviceAccountNumber = "65028609986509006138";
};
#endif // MAINWINDOW_H
