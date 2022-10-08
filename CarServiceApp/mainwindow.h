#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private slots:
    void on_SignIn_button_clicked();

    void on_workers_search_button_clicked();

private:
    Ui::MainWindow *ui;

private:
    DataBaseCarServiceDAO dao;
};
#endif // MAINWINDOW_H
