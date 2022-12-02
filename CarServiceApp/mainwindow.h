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

    void on_cashtransfer_button_clicked();

    void on_services_button_clicked();

    void on_work_in_action_button_clicked();

    void on_cashaccounts_button_clicked();

    void on_search_car_comp_button_clicked();

    void on_search_transfer_button_clicked();

    void on_search_repair_works_button_clicked();

    void on_search_is_ended_checkBox_stateChanged(int arg1);

    void on_hire_button_clicked();

    void on_register_button_clicked();

    void on_delet_user_button_clicked();

    void on_givesalary_button_clicked();

    void on_car_components_button_clicked();

    void on_new_equipment_button_clicked();

    void on_new_component_button_clicked();

    void on_new_cashtransfer_button_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer = new QTimer();

    DataBaseCarServiceDAO dao;

private:

    void setWarning(const QString& warning, int time = 5);
    QString serviceAccountNumber = "65028609986509006138";
};
#endif // MAINWINDOW_H
