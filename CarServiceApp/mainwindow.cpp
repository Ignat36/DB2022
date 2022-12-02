#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "newuserdialog.h"
#include "newcomponentdialog.h"
#include "newdocumentdialog.h"
#include "newworkerdialog.h"
#include "newequipmentdialog.h"
#include "newtransferdialog.h"
#include "deleteuserdialog.h"
#include "QDebug"
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(resetWarning()));

    BindComboBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDisplaiedText(std::vector<QString> strings)
{
    QString text = "";

    for (auto i : strings) {
        text += (i + "\n");
    }

    ui->data_display_screen->setText(text);
}

void MainWindow::setDisplaiedText(const QString& string)
{
    ui->data_display_screen->setText(string);
}

void MainWindow::BindComboBox()
{
    ui->transfer_search_ytpe_comboBox->addItem("Оплата работ");
    ui->transfer_search_ytpe_comboBox->addItem("Зарплата работникам");

    ui->transfer_search_ytpe_comboBox->setEditable(true);
    ui->transfer_search_ytpe_comboBox->lineEdit()->setReadOnly(true);
    ui->transfer_search_ytpe_comboBox->lineEdit()->setAlignment(Qt::AlignCenter);

    for (int i = 0 ; i < ui->transfer_search_ytpe_comboBox->count() ; ++i) {
        ui->transfer_search_ytpe_comboBox->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
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
    QString name = ui->person_serch_line_edit->text();

    setDisplaiedText(dao.GetWorkersStr(name));
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

void MainWindow::on_client_search_button_clicked()
{
    QString name = ui->person_serch_line_edit->text();

    setDisplaiedText(dao.GetClientsStr(name));
}

void MainWindow::on_workingequipment_button_clicked()
{
    auto eqps = dao.GetEquipments();

    std::vector<QString> eqps_str;

    for (auto i: eqps)
        eqps_str.push_back(i.toString());

    setDisplaiedText(eqps_str);
}

void MainWindow::on_components_button_clicked()
{
    auto comps = dao.GetComponents();

    std::vector<QString> comps_str;

    for (auto i: comps)
        comps_str.push_back(i.toString());

    setDisplaiedText(comps_str);
}

void MainWindow::on_exit_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_cashtransfer_button_clicked()
{
    setDisplaiedText(dao.GetTransfersStr(""));
}

void MainWindow::on_services_button_clicked()
{
    auto serv = dao.GetServices();

    std::vector<QString> servs_str;

    for (auto i: serv)
        servs_str.push_back(i.toString());

    setDisplaiedText(servs_str);
}

void MainWindow::on_work_in_action_button_clicked()
{
    setDisplaiedText(dao.GetAllDocumentsStr());
}

void MainWindow::on_cashaccounts_button_clicked()
{
    setDisplaiedText(dao.GetCashAccountsStr(""));
}

void MainWindow::on_search_car_comp_button_clicked()
{
    auto comps = dao.GetComponent_Name(ui->search_car_comp_line_edit->text());

    std::vector<QString> comps_str;

    for (auto i: comps)
        comps_str.push_back(i.toString());

    setDisplaiedText(comps_str);
}

void MainWindow::on_search_transfer_button_clicked()
{
    QString name = ui->search_by_sender_line_edit->text();
    QString type = ui->transfer_search_ytpe_comboBox->currentIndex() == 0 ? "Client" : "Worker";

    setDisplaiedText(dao.GetTransfersStr(name, type));
}

void MainWindow::on_search_repair_works_button_clicked()
{
    QString fio = ui->search_repair_by_client_line_edit->text();
    QString car = ui->search_repair_by_car_line_edit->text();
    QString ad = ui->search_repair_begin_date_dateEdit->text();
    QString ed = ui->search_repair_end_date_dateEdit->isEnabled() ? ui->search_repair_end_date_dateEdit->text() : "";

    setDisplaiedText(dao.GetDocumentsStr(fio, car, ad, ed));
}

void MainWindow::on_search_is_ended_checkBox_stateChanged(int arg1)
{
    // qDebug() << arg1;

    if (arg1)
    {
        ui->search_repair_end_date_dateEdit->setEnabled(false);
    }
    else
    {
        ui->search_repair_end_date_dateEdit->setEnabled(true);
    }
}

void MainWindow::on_hire_button_clicked()
{
    NewWorkerDialog dialog;
    dialog.setModal(true);
    dialog.exec();

    if (dialog.FIO != "")
        dao.HireWorker(dialog.FIO, dialog.phone, dialog.mail, "2022-12-02", dialog.salary, dialog.Qualification);
}

void MainWindow::on_register_button_clicked()
{
    NewUserDialog dialog;
    dialog.setModal(true);
    dialog.exec();

    if (dialog.login != "")
        dao.PutUser(User(dialog.login, dialog.password, dialog.roleid));
}

void MainWindow::on_delet_user_button_clicked()
{
    DeleteUserDialog dialog;

    dialog.setModal(true);
    dialog.exec();

    if (dialog.login != "")
        dao.DeleteUser(dao.GetUser(dialog.login, dialog.password).idUser);
}

void MainWindow::on_givesalary_button_clicked()
{
    dao.GiveSalary();
}

void MainWindow::on_car_components_button_clicked() // new document
{
    NewDocumentDialog dialog;
    dialog.setModal(true);
    dialog.exec();

    if (dialog.FIO != "")
        dao.NewClient(dialog.FIO, dialog.Phone, dialog.Mail, "2022-12-02", dialog.Brand, dialog.Style, dialog.Model);
}

void MainWindow::on_new_equipment_button_clicked()
{
    NewEquipmentDialog dialog;
    dialog.setModal(true);
    dialog.exec();

    if (dialog.Name != "")
        dao.PutEquipment(WorkingEquipment(dialog.Name, dialog.Description, "2000-01-01", dialog.Price));
}

void MainWindow::on_new_component_button_clicked()
{
    NewComponentDialog dialog;
    dialog.setModal(true);
    dialog.exec();

    if (dialog.Name != "")
        dao.PutComponent(Component(dialog.Name, "2000-01-01", dialog.Price));
}

void MainWindow::on_new_cashtransfer_button_clicked()
{
    NewTransferDialog dialog;
    dialog.setModal(true);
    dialog.exec();

    if (dialog.type != "")
        dao.PutTransfer(Transfer(dialog.cash, dao.GetCashAccount_Number(dialog.cardNumber).idCashAccount, dialog.type));
}
