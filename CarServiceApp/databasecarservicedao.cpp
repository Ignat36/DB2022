#include "databasecarservicedao.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <exception>
#include <QDebug>
#include <QString>

// Create connection
DataBaseCarServiceDAO::DataBaseCarServiceDAO() : isConnected(false)
{
    CreateConnection();
   // test();
}


//Disconnect from data base
DataBaseCarServiceDAO::~DataBaseCarServiceDAO()
{
    CloseConnection();
}


bool DataBaseCarServiceDAO::CreateConnection()
{
    if(isConnected)
        return true;

    DataBase = QSqlDatabase::addDatabase("QPSQL");
    DataBase.setHostName("localhost");
    DataBase.setPort(5432);
    DataBase.setPassword("36623");
    DataBase.setDatabaseName("test_db");
    DataBase.setUserName("postgres");

    if(!DataBase.open())
    {
        //QMessageBox::critical(0,"Cannot open database", "Unable to establish a database connection.",QMessageBox::Cancel);// вывести ошибку
        qDebug()<<DataBase.lastError().text();// Вывод сообщения об ошибке

        return false;
    }

    //QMessageBox::information(0,"Successfully","Establish a database connection",QMessageBox::Ok);// быстрый успех
    isConnected = true;
    return true;
}

void DataBaseCarServiceDAO::CloseConnection()
{
    if(!isConnected)
        return;

    DataBase.close();
    isConnected = false;

    return;
}

void DataBaseCarServiceDAO::test()
{
//    if (!PutPerson(Person("ignat shar", "1", "none")))
//        qDebug()<<"error\n";
//    if (!PutPerson(Person("egor penis", "2", "none")))
//        qDebug()<<"error\n";
//    if (!PutPerson(Person("vanya kar", "3", "none")))
//        qDebug()<<"error\n";
//    if (!PutPerson(Person("roma kez", "4", "none")))
//        qDebug()<<"error\n";
//    if (!PutPerson(Person("igor anal", "5", "none")))
//        qDebug()<<"error\n";
//    if (!PutPerson(Person("lexa akusher", "6", "none")))
//        qDebug()<<"error\n";

//    std::vector<Person> cl_one = GetPersonFIO("a");
//    std::vector<Person> cl_two = GetPersonFIO("g");
//    std::vector<Person> cl_fore = GetPersonFIO("ig");

//    Person one = GetPerson(cl_one.front().idPerson);
//    one.PhoneNumber = "+375293555104";
//    UpdatePerson(one, false);

//    std::vector<Person> all = GetPersons();

//    for(auto i: all)
    //        DeletePerson(i.idPerson);
}

bool DataBaseCarServiceDAO::GiveSalary()
{
    QSqlQuery query;
    return query.exec(QString("call paysalary()"));
}

bool DataBaseCarServiceDAO::HireWorker(QString FIO, QString Phone, QString Mail, QString Date, double salary, QString Qualification)
{
    QSqlQuery query;
    return query.exec(QString("call hireworker('%1', '%2', '%3', '%4', '%5', '%6')")
                      .arg(FIO)
                      .arg(Phone)
                      .arg(Mail)
                      .arg(Date)
                      .arg(salary)
                      .arg(Qualification));
}

bool DataBaseCarServiceDAO::NewClient(QString FIO, QString Phone, QString Mail, QString Date, QString Brand, QString Style, QString Model)
{
   // newclient(pfio, phone, mail, curdate, brandname, bodystylename, modelname)
    QSqlQuery query;
    return query.exec(QString("call newclient('%1', '%2', '%3', '%4', '%5', '%6', '%7')")
                      .arg(FIO)
                      .arg(Phone)
                      .arg(Mail)
                      .arg(Date)
                      .arg(Brand)
                      .arg(Style)
                      .arg(Style));
}

///////////////////////////////////////////////////////////////////////////
///                                User                                 ///
///////////////////////////////////////////////////////////////////////////

User DataBaseCarServiceDAO::GetUser(QString Login, QString Password)
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM users WHERE login='%1' AND password='%2'").arg(Login).arg(Password));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Log = query.value(1).toString();
        QString Pas = query.value(2).toString();
        int Role_idRole = query.value(3).toInt();
        return User(id, Log, Pas, Role_idRole);
    }

    throw std::runtime_error(QString("Incorrect user : %1 : %2").arg(Login).arg(Password).toStdString());
}

bool DataBaseCarServiceDAO::PutUser(User user)
{
    QSqlQuery query;
    QString str = QString("INSERT INTO users(login, password, role_idrole) VALUES ('%1','%2', '%3')")
            .arg(user.Login)
            .arg(user.Password)
            .arg(user.Role_idRole);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateUser(User user, bool CreateIfNotExists)
{
    if(!user.idUser)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE users SET login='%1', password='%2', role_idrole='%3' WHERE iduser=%4")
                           .arg(user.Login)
                           .arg(user.Password)
                           .arg(user.Role_idRole)
                           .arg(user.idUser));
    if ( ! flag && CreateIfNotExists)
    {
        return PutUser(user);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteUser(int idUser)
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM users WHERE iduser=%1")
                      .arg(idUser));
}

///////////////////////////////////////////////////////////////////////////
///                                Role                                 ///
///////////////////////////////////////////////////////////////////////////

Role DataBaseCarServiceDAO::GetRole(int idRole)
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM role WHERE idrole=%1").arg(idRole));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        return Role(id, Name);
    }

    throw std::runtime_error(QString("Incorrect id role : %1").arg(idRole).toStdString());
}

bool DataBaseCarServiceDAO::PutRole(Role role)
{
    QSqlQuery query;
    QString str = QString("INSERT INTO role(name) VALUES ('%1')")
            .arg(role.Name);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateRole(Role role, bool CreateIfNotExists)
{
    if(!role.idRole)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE role SET name='%1' WHERE idrole=%2")
                           .arg(role.Name)
                           .arg(role.idRole));
    if ( ! flag && CreateIfNotExists)
    {
        return PutRole(role);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteRole(int idRole)
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM role WHERE idrole=%1")
                      .arg(idRole));
}

///////////////////////////////////////////////////////////////////////////
///                                Component                            ///
///////////////////////////////////////////////////////////////////////////

Component DataBaseCarServiceDAO::GetComponent(int idComponent)
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM component WHERE idcomponent=%1").arg(idComponent));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        double Price = query.value(2).toDouble();
        QString Date = query.value(3).toString();
        return Component(id, Name, Date, Price);
    }

    throw std::runtime_error(QString("Incorrect id component : %1").arg(idComponent).toStdString());
}

std::vector<Component> DataBaseCarServiceDAO::GetComponent_Name(QString Name)
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM component WHERE name ilike '%%1%'").arg(Name));
    std::vector<Component> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        double Price = query.value(2).toDouble();
        QString Date = query.value(3).toString();
        result.push_back(Component(id, Name, Date, Price));
    }

    return result;
}

std::vector<Component> DataBaseCarServiceDAO::GetComponents()
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM component"));
    std::vector<Component> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        double Price = query.value(2).toDouble();
        QString Date = query.value(3).toString();
        result.push_back(Component(id, Name, Date, Price));
    }

    return result;
}

bool DataBaseCarServiceDAO::PutComponent(Component component)
{
    QSqlQuery query;
    QString str = QString("INSERT INTO component(name, price, dateofmanufacture) VALUES ('%1', '%2', '%3')")
            .arg(component.Name)
            .arg(component.Price)
            .arg(component.DateOfManufacture);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateComponent(Component component, bool CreateIfNotExists)
{
    if(!component.idComponent)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE component SET name='%1', price='%2', dateofmanufacture='%3' WHERE idcomponent=%4")
                           .arg(component.Name)
                           .arg(component.Price)
                           .arg(component.DateOfManufacture)
                           .arg(component.idComponent));
    if ( ! flag && CreateIfNotExists)
    {
        return PutComponent(component);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteComponent(int idComponent)
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM component WHERE idcomponent=%1")
                      .arg(idComponent));
}

///////////////////////////////////////////////////////////////////////////
///                                Car                                  ///
///////////////////////////////////////////////////////////////////////////

Car DataBaseCarServiceDAO::GetCar(int idCar) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM car WHERE idcar=%1").arg(idCar));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString defects = query.value(1).toString();
        int idPerson = query.value(2).toInt();
        int idModel = query.value(3).toInt();
        return Car(id, idModel, defects, idPerson);
    }

    throw std::runtime_error(QString("Incorrect idCar : %1").arg(idCar).toStdString());
}

std::vector<Car> DataBaseCarServiceDAO::GetCar_Client(int Client_Person_idPerson) // SELECT many
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM car WHERE client_person_idperson=%1").arg(Client_Person_idPerson));
    std::vector<Car> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString defects = query.value(1).toString();
        int idPerson = query.value(2).toInt();
        int idModel = query.value(3).toInt();
        result.push_back(Car(id, idModel, defects, idPerson));
    }

    return result;
}

std::vector<Car> DataBaseCarServiceDAO::GetCars() // SELECT ALL
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM car"));
    std::vector<Car> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString defects = query.value(1).toString();
        int idPerson = query.value(2).toInt();
        int idModel = query.value(3).toInt();
        result.push_back(Car(id, idModel, defects, idPerson));
    }

    return result;
}

bool DataBaseCarServiceDAO::PutCar(Car car) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO car(defects, client_person_idperson, model_idmodel) VALUES ('%1', %2, %3)")
            .arg(car.Defects)
            .arg(car.Client_Person_idPerson)
            .arg(car.Model_idModel);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateCar(Car car, bool CreateIfNotExists) // UPDATE
{
    if(!car.idCar)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE car SET defects='%1', client_person_idperson=%2, model_idmodel=%3 WHERE idcar=%4")
                           .arg(car.Defects)
                           .arg(car.Client_Person_idPerson)
                           .arg(car.Model_idModel)
                           .arg(car.idCar));
    if ( ! flag && CreateIfNotExists)
    {
        return PutCar(car);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteCar(int idCar) // DELETE
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM car WHERE idcar=%1")
                      .arg(idCar));
}

///////////////////////////////////////////////////////////////////////////
///                                Client                               ///
///////////////////////////////////////////////////////////////////////////

Client DataBaseCarServiceDAO::GetClient(int Person_idPerson) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM client WHERE person_idperson=%1").arg(Person_idPerson));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString LastVisit = query.value(1).toString();
        return Client(id, LastVisit);
    }

    throw std::runtime_error(QString("Incorrect id Client : %1").arg(Person_idPerson).toStdString());
}

std::vector<QString> DataBaseCarServiceDAO::GetClientsStr(QString Name)
{
    QSqlQuery query;
    query.exec(QString("SELECT person.idperson, client.lastvisit, person.fio, person.phonenumber, person.mailadres FROM client INNER JOIN person ON person.idperson = client.person_idperson WHERE person.fio ilike '%%1%'")
               .arg(Name));
    std::vector<QString> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString LastVisit = query.value(1).toString();
        QString FIO = query.value(2).toString();
        QString PhoneNumber = query.value(3).toString();
        QString MailAdres = query.value(4).toString();

        QSqlQuery q;
        q.exec(QString("SELECT document.workacceptdate, document.workdonedate, document.price, brand.name, model.name, bodystyle.stylename, person.fio FROM document INNER JOIN car ON car.idcar = document.car_idcar INNER JOIN person ON person.idperson = car.client_person_idperson INNER JOIN model ON model.idmodel = car.model_idmodel INNER JOIN brand ON brand.idbrand = model.brand_idbrand INNER JOIN bodystyle ON bodystyle.idbodystyle = model.bodystyle_idbodystyle WHERE person.idperson = %1")
               .arg(id));

        QString pers =    QString("\nИмя заказчика   : ") + FIO
                        + QString("\nТелефон         : ") + PhoneNumber
                        + QString("\nEmail           : ") + MailAdres
                        + QString("\nПоследний визит : ") + LastVisit;

        result.push_back(pers);

        while (q.next())
        {
            QString acceptDate = q.value(0).toString();
            QString doneDate = q.value(1).toString();
            double price = q.value(2).toDouble();
            QString Brand = q.value(3).toString();
            QString Model = q.value(4).toString();
            QString Style = q.value(5).toString();
            QString FIO = q.value(6).toString();

            QString record =  QString("   ----------------------------------------------------->")
                            + QString("\n       Дата начала работ    : ") + acceptDate
                            + QString("\n       Дата окончания работ : ") + doneDate
                            + QString("\n       Цена работ           : ") + QString::number(price)
                            + QString("\n       Марка машины         : ") + Brand
                            + QString("\n       Модель машины        : ") + Model
                            + QString("\n       Тип кузова           : ") + Style
                            + QString("\n   ----------------------------------------------------->") ;

            result.push_back(record);
        }
    }

    return result;
}

std::vector<Client> DataBaseCarServiceDAO::GetClients() // SELECT ALL
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM client"));
    std::vector<Client> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString LastVisit = query.value(1).toString();
        result.push_back(Client(id, LastVisit));
    }

    return result;
}

bool DataBaseCarServiceDAO::PutClient(Client client) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO client(person_idperson, lastvisit) VALUES (%1, '%2')")
            .arg(client.Person_idPerson)
            .arg(client.LastVisit);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateClient(Client client, bool CreateIfNotExists) // UPDATE
{
    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE client SET lastvisit='%1' WHERE person_idperson=%2")
                           .arg(client.LastVisit)
                           .arg(client.Person_idPerson));

    if ( ! flag && CreateIfNotExists)
    {
        return PutClient(client);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteClinet(int Person_idPerson) // DELETE
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM client WHERE person_idperson=%1")
                      .arg(Person_idPerson));
}

///////////////////////////////////////////////////////////////////////////
///                                Worker                               ///
///////////////////////////////////////////////////////////////////////////

Worker DataBaseCarServiceDAO::GetWorker(int Person_idPerson) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM worker WHERE person_idperson=%1").arg(Person_idPerson));

    while (query.next()) {

        double Salary = query.value(0).toDouble();
        QString HireDate = query.value(1).toString();
        int UnpaidHours = query.value(2).toInt();
        int PaidHours = query.value(3).toInt();
        QString Qualification = query.value(4).toString();
        QString PersonalQualities = query.value(5).toString();
        int id = query.value(6).toInt();
        return Worker(id, PersonalQualities, Salary, UnpaidHours, PaidHours, HireDate, Qualification);
    }

    throw std::runtime_error(QString("Incorrect id Worker : %1").arg(Person_idPerson).toStdString());
}

std::vector<QString> DataBaseCarServiceDAO::GetWorkersStr(QString Name)
{
    QSqlQuery query;
    query.exec(QString("SELECT person.idperson, person.fio, person.phonenumber, person.mailadres, worker.salary, worker.paidhours, worker.unpaidhours, worker.hiredate, worker.qualification, worker.personalqualities FROM worker INNER JOIN person ON person.idperson = worker.person_idperson WHERE person.fio ilike '%%1%'")
               .arg(Name));
    std::vector<QString> result;

    while (query.next()) {
        int id = query.value(0).toInt(); Q_UNUSED(id);
        QString FIO = query.value(1).toString();
        QString PhoneNumber = query.value(2).toString();
        QString MailAdres = query.value(3).toString();
        double salary = query.value(4).toDouble();
        int paidh = query.value(5).toInt();
        int unpaidh = query.value(6).toInt();
        QString hireDate = query.value(7).toString();
        QString Qualification = query.value(8).toString();
        QString PersonalQalities = query.value(9).toString();

        QString pers =    QString("   ----------------------------------------------------->")
                        + QString("\n       ФИО                  : ") + FIO
                        + QString("\n       Телефон              : ") + PhoneNumber
                        + QString("\n       Email                : ") + MailAdres
                        + QString("\n       Зарплата             : ") + QString::number(salary)
                        + QString("\n       Оплаченые часы       : ") + QString::number(paidh)
                        + QString("\n       Не оплаченые часы    : ") + QString::number(unpaidh)
                        + QString("\n       Дата начала работ    : ") + hireDate
                        + QString("\n       Квалификация         : ") + Qualification
                        + QString("\n       Персональные качества: ") + PersonalQalities
                        + QString("\n   ----------------------------------------------------->") ;

        result.push_back(pers);
    }

    return result;
}

std::vector<Worker> DataBaseCarServiceDAO::GetWorkers() // SELECT ALL
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM worker"));
    std::vector<Worker> result;

    while (query.next()) {
        double Salary = query.value(0).toDouble();
        QString HireDate = query.value(1).toString();
        int UnpaidHours = query.value(2).toInt();
        int PaidHours = query.value(3).toInt();
        QString Qualification = query.value(4).toString();
        QString PersonalQualities = query.value(5).toString();
        int id = query.value(6).toInt();
        result.push_back(Worker(id, PersonalQualities, Salary, UnpaidHours, PaidHours, HireDate, Qualification));
    }

    return result;
}

bool DataBaseCarServiceDAO::PutWorker(Worker worker) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO worker(salary, hiredate, unpaidhours, paidhours, qualification, personalqualities, person_idperson) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7')")
            .arg(worker.Salary)
            .arg(worker.HireDate)
            .arg(worker.UnpaidHours)
            .arg(worker.PaidHours)
            .arg(worker.Qualification)
            .arg(worker.PersonalQualities)
            .arg(worker.Person_idPerson);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateWorker(Worker worker, bool CreateIfNotExists) // UPDATE
{
    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE worker SET salary='%1', hiredate='%2', unpaidhours='%3', paidhours='%4', qualification='%5', personalqualities='%6' WHERE person_idperson=%2")
                           .arg(worker.Salary)
                           .arg(worker.HireDate)
                           .arg(worker.UnpaidHours)
                           .arg(worker.PaidHours)
                           .arg(worker.Qualification)
                           .arg(worker.PersonalQualities)
                           .arg(worker.Person_idPerson));

    if ( ! flag && CreateIfNotExists)
    {
        return PutWorker(worker);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteWorker(int Person_idPerson) // DELETE
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM worker WHERE person_idperson=%1")
                      .arg(Person_idPerson));
}

///////////////////////////////////////////////////////////////////////////
///                           WorkingEquipment                          ///
///////////////////////////////////////////////////////////////////////////

WorkingEquipment DataBaseCarServiceDAO::GetEquipment(int idEquipment)
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM workingequipment WHERE idworkingequipment=%1").arg(idEquipment));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        QString AssignmentOfUse = query.value(2).toString();
        QString LastUsedDate = query.value(3).toString();
        double Price = query.value(4).toDouble();
        return WorkingEquipment(id, Name, AssignmentOfUse, LastUsedDate, Price);
    }

    throw std::runtime_error(QString("Incorrect id Equipment : %1").arg(idEquipment).toStdString());
}

std::vector<WorkingEquipment> DataBaseCarServiceDAO::GetEquipment_Name(QString Name)
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM workingequipment WHERE name ilike '%%1%'").arg(Name));
    std::vector<WorkingEquipment> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        QString AssignmentOfUse = query.value(2).toString();
        QString LastUsedDate = query.value(3).toString();
        double Price = query.value(4).toDouble();
        result.push_back(WorkingEquipment(id, Name, AssignmentOfUse, LastUsedDate, Price));
    }

    return result;
}

std::vector<WorkingEquipment> DataBaseCarServiceDAO::GetEquipments()
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM workingequipment"));
    std::vector<WorkingEquipment> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        QString AssignmentOfUse = query.value(2).toString();
        QString LastUsedDate = query.value(3).toString();
        double Price = query.value(4).toDouble();
        result.push_back(WorkingEquipment(id, Name, AssignmentOfUse, LastUsedDate, Price));
    }

    return result;
}

bool DataBaseCarServiceDAO::PutEquipment(WorkingEquipment equipment)
{
    QSqlQuery query;
    QString str = QString("INSERT INTO workingequipment(name, assignmentofuse, lasttimeused, price) VALUES ('%1', '%2', '%3', '%4')")
            .arg(equipment.Name)
            .arg(equipment.AssignmentOfUse)
            .arg(equipment.LastUsedDate)
            .arg(equipment.Price);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateEquipment(WorkingEquipment equipment, bool CreateIfNotExists)
{
    if(!equipment.idWorkingEquipment)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE workingequipment SET name='%1', assignmentofuse='%2', lasttimeused='%3', price='%4' WHERE idworkingequipment=%5")
                           .arg(equipment.Name)
                           .arg(equipment.AssignmentOfUse)
                           .arg(equipment.LastUsedDate)
                           .arg(equipment.Price)
                           .arg(equipment.idWorkingEquipment));
    if ( ! flag && CreateIfNotExists)
    {
        return PutEquipment(equipment);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteEquipment(int idEquipment)
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM workingequipment WHERE idworkingequipment=%1")
                      .arg(idEquipment));
}

///////////////////////////////////////////////////////////////////////////
///                                Service                              ///
///////////////////////////////////////////////////////////////////////////

Service DataBaseCarServiceDAO::GetService(int idService) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM service WHERE idservice=%1").arg(idService));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Description = query.value(1).toString();
        double Price = query.value(2).toDouble();
        int ReqTimeH = query.value(3).toInt();
        QString Name = query.value(4).toString();
        return Service(id, Description, Price, ReqTimeH, Name);
    }

    throw std::runtime_error(QString("Incorrect id Person : %1").arg(idService).toStdString());
}

std::vector<Service> DataBaseCarServiceDAO::GetService_Name(QString Name) // SELECT many
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM service WHERE name ilike '%%1%'").arg(Name));
    std::vector<Service> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Description = query.value(1).toString();
        double Price = query.value(2).toDouble();
        int ReqTimeH = query.value(3).toInt();
        QString Name = query.value(4).toString();
        result.push_back(Service(id, Description, Price, ReqTimeH, Name));
    }

    return result;
}

std::vector<Service> DataBaseCarServiceDAO::GetServices() // SELECT ALL
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM service"));
    std::vector<Service> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Description = query.value(1).toString();
        double Price = query.value(2).toDouble();
        int ReqTimeH = query.value(3).toInt();
        QString Name = query.value(4).toString();
        result.push_back(Service(id, Description, Price, ReqTimeH, Name));
    }

    return result;
}

bool DataBaseCarServiceDAO::PutService(Service service) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO service(description, price, requiredtimeh, name) VALUES ('%1', '%2', '%3', '%4')")
            .arg(service.Description)
            .arg(service.Price)
            .arg(service.RequiredTimeH)
            .arg(service.Name);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateService(Service service, bool CreateIfNotExists) // UPDATE
{
    if(!service.idService)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE service SET description='%1', price='%2', requiredtimeh='%3', name='%4' WHERE idservice=%5")
                           .arg(service.Description)
                           .arg(service.Price)
                           .arg(service.RequiredTimeH)
                           .arg(service.Name)
                           .arg(service.idService));
    if ( ! flag && CreateIfNotExists)
    {
        return PutService(service);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteService(int idService) // DELETE
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM service WHERE idservice=%1")
                      .arg(idService));
}

///////////////////////////////////////////////////////////////////////////
///                              CashAccount                            ///
///////////////////////////////////////////////////////////////////////////

CashAccount DataBaseCarServiceDAO::GetCashAccount(int idCashAccount) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM cashaccount WHERE idcashaccount=%1").arg(idCashAccount));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString CardNumber = query.value(1).toString();
        int Person_idPerson = query.value(2).toInt();
        return CashAccount(id, CardNumber, Person_idPerson);
    }

    throw std::runtime_error(QString("Incorrect id Cash account : %1").arg(idCashAccount).toStdString());
}

CashAccount DataBaseCarServiceDAO::GetCashAccount_Number(QString CardNumber) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM cashaccount WHERE cardnumber ilike '%%1%'").arg(CardNumber));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString CardNumber = query.value(1).toString();
        int Person_idPerson = query.value(2).toInt();
        return CashAccount(id, CardNumber, Person_idPerson);
    }

    throw std::runtime_error(QString("Incorrect card number Cash account : %1").arg(CardNumber).toStdString());
}

std::vector<CashAccount> DataBaseCarServiceDAO::GetCashAccount_idPerson(int Person_idPerson) // SELECT many
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM cashaccount WHERE person_idperson=%1").arg(Person_idPerson));
    std::vector<CashAccount> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString CardNumber = query.value(1).toString();
        int Person_idPerson = query.value(2).toInt();
        result.push_back(CashAccount(id, CardNumber, Person_idPerson));
    }

    return result;
}

std::vector<CashAccount> DataBaseCarServiceDAO::GetCashAccounts() // SELECT all
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM cashaccount"));
    std::vector<CashAccount> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString CardNumber = query.value(1).toString();
        int Person_idPerson = query.value(2).toInt();
        result.push_back(CashAccount(id, CardNumber, Person_idPerson));
    }

    return result;
}

std::vector<QString> DataBaseCarServiceDAO::GetCashAccountsStr(QString Name)
{
        QSqlQuery query;
        query.exec(QString("select cashaccount.cardnumber, person.fio from cashaccount inner join person ON person.idperson = cashaccount.person_idperson where person.fio ilike '%%1%'")
                   .arg(Name));
        std::vector<QString> result;

        while (query.next()) {
            QString CardNumber = query.value(0).toString();
            QString FIO = query.value(1).toString();


            QString record =  QString("   ----------------------------------------------------->")
                            + QString("\n       Номер счета      : ") + CardNumber
                            + QString("\n       ФИО              : ") + FIO
                            + QString("\n   ----------------------------------------------------->") ;

            result.push_back(record);
        }

        return result;
}

bool DataBaseCarServiceDAO::PutCashAccount(CashAccount cashaccount) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO cashaccount(cardnumber, person_idperson) VALUES ('%1', '%2')")
            .arg(cashaccount.CardNumber)
            .arg(cashaccount.Person_idPerson);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateCashAccount(CashAccount cashaccount, bool CreateIfNotExists) // UPDATE
{
    if(!cashaccount.idCashAccount)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE cashaccount SET cardnumber='%1', person_idperson='%2' WHERE idcashaccount=%3")
                           .arg(cashaccount.CardNumber)
                           .arg(cashaccount.Person_idPerson)
                           .arg(cashaccount.idCashAccount));
    if ( ! flag && CreateIfNotExists)
    {
        return PutCashAccount(cashaccount);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteCashAccount(int idCashAccount) // DELETE
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM cashaccount WHERE idcashaccount=%1")
                      .arg(idCashAccount));
}

///////////////////////////////////////////////////////////////////////////
///                             CashTransfer                            ///
///////////////////////////////////////////////////////////////////////////

Transfer DataBaseCarServiceDAO::GetTransfer(int idTransfer) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM cashtransfer WHERE idcashtransfer=%1").arg(idTransfer));

    while (query.next()) {
        int id = query.value(0).toInt();
        double Cash = query.value(1).toDouble();
        int CashAccount_idCashAccount = query.value(2).toInt();
        QString Type = query.value(3).toString();
        return Transfer(id, Cash, CashAccount_idCashAccount, Type);
    }

    throw std::runtime_error(QString("Incorrect id CashTransfer : %1").arg(idTransfer).toStdString());
}

std::vector<Transfer> DataBaseCarServiceDAO::GetTransfer_idCashAccount(int CashAccount_idCashAccount) // SELECT many
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM cashtransfer WHERE cashaccount_idcashaccount=%1").arg(CashAccount_idCashAccount));
    std::vector<Transfer> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        double Cash = query.value(1).toDouble();
        int CashAccount_idCashAccount = query.value(2).toInt();
        QString Type = query.value(3).toString();
        result.push_back(Transfer(id, Cash, CashAccount_idCashAccount, Type));
    }

    return result;
}

std::vector<Transfer> DataBaseCarServiceDAO::GetTransfers() // SLECT all
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM cashtransfer"));
    std::vector<Transfer> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        double Cash = query.value(1).toDouble();
        int CashAccount_idCashAccount = query.value(2).toInt();
        QString Type = query.value(3).toString();
        result.push_back(Transfer(id, Cash, CashAccount_idCashAccount, Type));
    }

    return result;
}

std::vector<QString> DataBaseCarServiceDAO::GetTransfersStr(QString FIO)
{
    QSqlQuery query;
    query.exec(QString("SELECT cashtransfer.cash, cashaccount.cardnumber, person.fio FROM cashtransfer INNER JOIN cashaccount ON cashaccount.idcashaccount = cashtransfer.cashaccount_idcashaccount INNER JOIN person ON person.idperson = cashaccount.person_idperson WHERE person.fio ILIKE '%%1%'")
               .arg(FIO));
    std::vector<QString> result;

    while (query.next()) {
        double sum = query.value(0).toDouble();
        QString CrandNumber = query.value(1).toString();
        QString FIO = query.value(2).toString();

        QString record =  QString("   ----------------------------------------------------->")
                        + QString("\n       ФИО                  : ") + FIO
                        + QString("\n       Номер счета          : ") + CrandNumber
                        + QString("\n       Сумма перевода       : ") + QString::number(sum)
                        + QString("\n   ----------------------------------------------------->") ;

        result.push_back(record);
    }

    return result;
}

std::vector<QString> DataBaseCarServiceDAO::GetTransfersStr(QString FIO, QString type)
{
    QSqlQuery query;
    query.exec(QString("SELECT cashtransfer.cash, cashaccount.cardnumber, person.fio FROM cashtransfer INNER JOIN cashaccount ON cashaccount.idcashaccount = cashtransfer.cashaccount_idcashaccount INNER JOIN person ON person.idperson = cashaccount.person_idperson WHERE cashtransfer.type = '%1' AND person.fio ILIKE '%%2%'")
               .arg(type)
               .arg(FIO));
    std::vector<QString> result;

    while (query.next()) {
        double sum = query.value(0).toDouble();
        QString CrandNumber = query.value(1).toString();
        QString FIO = query.value(2).toString();

        QString record =  QString("   ----------------------------------------------------->")
                        + QString("\n       ФИО                  : ") + FIO
                        + QString("\n       Номер счета          : ") + CrandNumber
                        + QString("\n       Сумма перевода       : ") + QString::number(sum)
                        + QString("\n   ----------------------------------------------------->") ;

        result.push_back(record);
    }

    return result;
}

bool DataBaseCarServiceDAO::PutTransfer(Transfer transfer) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO cashtransfer(cash, cashaccount_idcashaccount, type) VALUES ('%1', '%2', '%3')")
            .arg(transfer.Cash)
            .arg(transfer.CashAccount_idCashAccount)
            .arg(transfer.Type);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateTransfer(Transfer transfer, bool CreateIfNotExists) // UPDATE
{
    if(!transfer.idTransfer)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE cashtransfer SET cash='%1', cashaccount_idcashaccount='%2', type='%3' WHERE idcashtransfer=%4")
                           .arg(transfer.Cash)
                           .arg(transfer.CashAccount_idCashAccount)
                           .arg(transfer.Type)
                           .arg(transfer.idTransfer));
    if ( ! flag && CreateIfNotExists)
    {
        return PutTransfer(transfer);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteTransfer(int idTransfer) // DELETE
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM cashtransfer WHERE idcashtransfer=%1")
                      .arg(idTransfer));
}

///////////////////////////////////////////////////////////////////////////
///                              Document                               ///
///////////////////////////////////////////////////////////////////////////

Document DataBaseCarServiceDAO::GetDocument(int idDocument) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM document WHERE iddocument=%1").arg(idDocument));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Text = query.value(1).toString();
        int WorkedHours = query.value(2).toInt();
        int CashTransfer_idCashTransfer = query.value(3).toInt();
        QString AcceptDate = query.value(4).toString();
        QString DoneDate = query.value(5).toString();
        int Car_idCar = query.value(6).toInt();
        double Price = query.value(7).toDouble();

        return Document(id, Text, WorkedHours, CashTransfer_idCashTransfer, Car_idCar, AcceptDate, DoneDate, Price);
    }

    throw std::runtime_error(QString("Incorrect id Person : %1").arg(idDocument).toStdString());
}

std::vector<Document> DataBaseCarServiceDAO::GetDocument_idTransfer(int CashTransfer_idTransfer) // SLECT many
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM document WHERE cashtransfer_idcashtransfer=%1").arg(CashTransfer_idTransfer));
    std::vector<Document> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Text = query.value(1).toString();
        int WorkedHours = query.value(2).toInt();
        int CashTransfer_idCashTransfer = query.value(3).toInt();
        QString AcceptDate = query.value(4).toString();
        QString DoneDate = query.value(5).toString();
        int Car_idCar = query.value(6).toInt();
        double Price = query.value(7).toDouble();

        result.push_back( Document(id, Text, WorkedHours, CashTransfer_idCashTransfer, Car_idCar, AcceptDate, DoneDate, Price));
    }


    return result;
}

std::vector<Document> DataBaseCarServiceDAO::GetDocument_idCar(int Car_idCar) // SELECT many
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM document WHERE car_idcar=%1").arg(Car_idCar));
    std::vector<Document> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Text = query.value(1).toString();
        int WorkedHours = query.value(2).toInt();
        int CashTransfer_idCashTransfer = query.value(3).toInt();
        QString AcceptDate = query.value(4).toString();
        QString DoneDate = query.value(5).toString();
        int Car_idCar = query.value(6).toInt();
        double Price = query.value(7).toDouble();

        result.push_back( Document(id, Text, WorkedHours, CashTransfer_idCashTransfer, Car_idCar, AcceptDate, DoneDate, Price));
    }


    return result;
}

std::vector<Document> DataBaseCarServiceDAO::GetDocuments() // SELECT all
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM document"));
    std::vector<Document> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Text = query.value(1).toString();
        int WorkedHours = query.value(2).toInt();
        int CashTransfer_idCashTransfer = query.value(3).toInt();
        QString AcceptDate = query.value(4).toString();
        QString DoneDate = query.value(5).toString();
        int Car_idCar = query.value(6).toInt();
        double Price = query.value(7).toDouble();

        result.push_back( Document(id, Text, WorkedHours, CashTransfer_idCashTransfer, Car_idCar, AcceptDate, DoneDate, Price) );
    }


    return result;
}

std::vector<QString> DataBaseCarServiceDAO::GetDocumentsStr(QString FIO, QString car, QString begDate, QString endDate)
{
    QSqlQuery query;

    if (endDate == "")
        query.exec(QString("SELECT document.workacceptdate, document.workdonedate, document.price, brand.name, model.name, bodystyle.stylename, person.fio FROM document INNER JOIN car ON car.idcar = document.car_idcar INNER JOIN person ON person.idperson = car.client_person_idperson INNER JOIN model ON model.idmodel = car.model_idmodel INNER JOIN brand ON brand.idbrand = model.brand_idbrand INNER JOIN bodystyle ON bodystyle.idbodystyle = model.bodystyle_idbodystyle where person.fio ilike '%%1%' AND (model.name ilike '%%2%' OR brand.name ilike '%%3%' OR bodystyle.stylename ilike '%%4%') AND document.workacceptdate >= '%5' AND  document.workdonedate is NULL")
                   .arg(FIO)
                   .arg(car)
                   .arg(car)
                   .arg(car)
                   .arg(begDate));
    else
        query.exec(QString("SELECT document.workacceptdate, document.workdonedate, document.price, brand.name, model.name, bodystyle.stylename, person.fio FROM document INNER JOIN car ON car.idcar = document.car_idcar INNER JOIN person ON person.idperson = car.client_person_idperson INNER JOIN model ON model.idmodel = car.model_idmodel INNER JOIN brand ON brand.idbrand = model.brand_idbrand INNER JOIN bodystyle ON bodystyle.idbodystyle = model.bodystyle_idbodystyle where person.fio ilike '%%1%' AND (model.name ilike '%%2%' OR brand.name ilike '%%3%' OR bodystyle.stylename ilike '%%4%') AND document.workacceptdate >= '%5' AND document.workdonedate <= '%6'")
                    .arg(FIO)
                    .arg(car)
                    .arg(car)
                    .arg(car)
                    .arg(begDate)
                    .arg(endDate));


    std::vector<QString> result;

    while (query.next()) {
        QString AcceptDate = query.value(0).toString();
        QString DoneDate = query.value(1).toString();
        double price = query.value(2).toDouble();
        QString Brand = query.value(3).toString();
        QString Model = query.value(4).toString();
        QString BodyStyle = query.value(5).toString();
        QString FIO = query.value(6).toString();

        QString pers =    QString("   ----------------------------------------------------->")
                        + QString("\n       ФИО                  : ") + FIO
                        + QString("\n       Дата начала работ    : ") + AcceptDate
                        + QString("\n       Дата окончания работ : ") + DoneDate
                        + QString("\n       Цена                 : ") + QString::number(price)
                        + QString("\n       Марка машины         : ") + Brand
                        + QString("\n       Модель машины        : ") + Model
                        + QString("\n       Тип кузова           : ") + BodyStyle
                        + QString("\n   ----------------------------------------------------->") ;

        result.push_back(pers);
    }

    return result;
}

std::vector<QString> DataBaseCarServiceDAO::GetAllDocumentsStr()
{
    QSqlQuery query;

    query.exec(QString("SELECT document.workacceptdate, document.workdonedate, document.price, brand.name, model.name, bodystyle.stylename, person.fio FROM document INNER JOIN car ON car.idcar = document.car_idcar INNER JOIN person ON person.idperson = car.client_person_idperson INNER JOIN model ON model.idmodel = car.model_idmodel INNER JOIN brand ON brand.idbrand = model.brand_idbrand INNER JOIN bodystyle ON bodystyle.idbodystyle = model.bodystyle_idbodystyle"));


    std::vector<QString> result;

    while (query.next()) {
        QString AcceptDate = query.value(0).toString();
        QString DoneDate = query.value(1).toString();
        double price = query.value(2).toDouble();
        QString Brand = query.value(3).toString();
        QString Model = query.value(4).toString();
        QString BodyStyle = query.value(5).toString();
        QString FIO = query.value(6).toString();

        QString pers =    QString("   ----------------------------------------------------->")
                        + QString("\n       ФИО                  : ") + FIO
                        + QString("\n       Дата начала работ    : ") + AcceptDate
                        + QString("\n       Дата окончания работ : ") + DoneDate
                        + QString("\n       Цена                 : ") + QString::number(price)
                        + QString("\n       Марка машины         : ") + Brand
                        + QString("\n       Модель машины        : ") + Model
                        + QString("\n       Тип кузова           : ") + BodyStyle
                        + QString("\n   ----------------------------------------------------->") ;

        result.push_back(pers);
    }

    return result;
}

bool DataBaseCarServiceDAO::PutDocument(Document document) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO document(text, workedhours, cashtransfer_idcashtransfer, workacceptdate, workdonedate, car_idcar, price) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7')")
            .arg(document.Text)
            .arg(document.WorkedHours)
            .arg(document.CashTransfer_idCashTransfer)
            .arg(document.AcceptDate)
            .arg(document.DoneDate)
            .arg(document.Car_idCar)
            .arg(document.Price);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateDocument(Document document, bool CreateIfNotExists) // UPDATE
{
    if(!document.idDocument)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE document SET text='%1', workedhours='%2', cashtransfer_idcashtransfer='%3', workacceptdate='%4', workdonedate='%5', car_idcar='%6', price='%7' WHERE iddocument=%8")
                           .arg(document.Text)
                           .arg(document.WorkedHours)
                           .arg(document.CashTransfer_idCashTransfer)
                           .arg(document.AcceptDate)
                           .arg(document.DoneDate)
                           .arg(document.Car_idCar)
                           .arg(document.Price)
                           .arg(document.idDocument));
    if ( ! flag && CreateIfNotExists)
    {
        return PutDocument(document);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteDocument(int idDocument) // DELETE
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM document WHERE iddocument=%1")
                      .arg(idDocument));
}

///////////////////////////////////////////////////////////////////////////
///                                Person                               ///
///////////////////////////////////////////////////////////////////////////

Person DataBaseCarServiceDAO::GetPerson(int idPerson) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM person WHERE idperson=%1").arg(idPerson));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString FIO = query.value(1).toString();
        QString PhoneNumber = query.value(2).toString();
        QString MailAdres = query.value(3).toString();
        return Person(id, FIO, PhoneNumber, MailAdres);
    }

    throw std::runtime_error(QString("Incorrect id Person : %1").arg(idPerson).toStdString());
}

std::vector<Person> DataBaseCarServiceDAO::GetPersonFIO(QString FIO) // SELECT many
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM person WHERE fio ilike '%%1%'").arg(FIO));
    std::vector<Person> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString FIO = query.value(1).toString();
        QString PhoneNumber = query.value(2).toString();
        QString MailAdres = query.value(3).toString();
        result.push_back(Person(id, FIO, PhoneNumber, MailAdres));
    }

    return result;
}

std::vector<Person> DataBaseCarServiceDAO::GetPersons() // SELECT ALL
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM person"));
    std::vector<Person> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString FIO = query.value(1).toString();
        QString PhoneNumber = query.value(2).toString();
        QString MailAdres = query.value(3).toString();
        result.push_back(Person(id, FIO, PhoneNumber, MailAdres));
    }

    return result;
}

bool DataBaseCarServiceDAO::PutPerson(Person person) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO person(fio, phonenumber, mailadres) VALUES ('%1', '%2', '%3')")
            .arg(person.FIO)
            .arg(person.PhoneNumber)
            .arg(person.MailAdres);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdatePerson(Person person, bool CreateIfNotExists) // UPDATE
{
    if(!person.idPerson)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE person SET fio='%1', phonenumber='%2', mailadres='%3' WHERE idperson=%4")
                           .arg(person.FIO)
                           .arg(person.PhoneNumber)
                           .arg(person.MailAdres)
                           .arg(person.idPerson));
    if ( ! flag && CreateIfNotExists)
    {
        return PutPerson(person);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeletePerson(int idPerson) // DELETE
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM person WHERE idperson=%1")
                      .arg(idPerson));
}

///////////////////////////////////////////////////////////////////////////
///                                Brand                                ///
///////////////////////////////////////////////////////////////////////////

Brand DataBaseCarServiceDAO::GetBrand(int idBrand) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM brand WHERE idbrand=%1").arg(idBrand));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        return Brand(id, Name);
    }

    throw std::runtime_error(QString("Incorrect id brand : %1").arg(idBrand).toStdString());
}

std::vector<Brand> DataBaseCarServiceDAO::GetBrandName(QString Name) // SLECT many
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM brand WHERE name ilike '%%1%'").arg(Name));
    std::vector<Brand> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        result.push_back(Brand(id, Name));
    }

    return result;
}

std::vector<Brand> DataBaseCarServiceDAO::GetBrands() // SELECT all
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM brand"));
    std::vector<Brand> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        result.push_back(Brand(id, Name));
    }

    return result;
}

bool DataBaseCarServiceDAO::PutBrand(Brand brand) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO brand(name) VALUES ('%1')")
            .arg(brand.Name);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateBrand(Brand brand, bool CreateIfNotExists) // UPDATE
{
    if(!brand.idBrand)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE brand SET name='%1' WHERE idbrand=%2")
                           .arg(brand.Name)
                           .arg(brand.idBrand));
    if ( ! flag && CreateIfNotExists)
    {
        return PutBrand(brand);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteBrand(int idBrand) // DELETE
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM brand WHERE idbrand=%1")
                      .arg(idBrand));
}

///////////////////////////////////////////////////////////////////////////
///                                BodyStyle                            ///
///////////////////////////////////////////////////////////////////////////

BodyStyle DataBaseCarServiceDAO::GetBodyStyle(int idBodyStyle) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM bodystyle WHERE idbodystyle=%1").arg(idBodyStyle));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        return BodyStyle(id, Name);
    }

    throw std::runtime_error(QString("Incorrect id bodystyle : %1").arg(idBodyStyle).toStdString());
}

std::vector<BodyStyle> DataBaseCarServiceDAO::GetBodyStyleName(QString Name) // SELECT many
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM bodystyle WHERE stylename ilike '%%1%'").arg(Name));
    std::vector<BodyStyle> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        result.push_back(BodyStyle(id, Name));
    }

    return result;
}

std::vector<BodyStyle> DataBaseCarServiceDAO::GetBodyStyles() // SELECT ALL
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM bodystyle"));
    std::vector<BodyStyle> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        result.push_back(BodyStyle(id, Name));
    }

    return result;
}

bool DataBaseCarServiceDAO::PutBodyStyle(BodyStyle bodystyle) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO bodystyle(stylename) VALUES ('%1')")
            .arg(bodystyle.Name);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateBodyStyle(BodyStyle bodystyle, bool CreateIfNotExists) // UPDATE
{
    if(!bodystyle.idBodyStyle)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE bodystyle SET stylename='%1' WHERE idbodystyle=%2")
                           .arg(bodystyle.Name)
                           .arg(bodystyle.idBodyStyle));
    if ( ! flag && CreateIfNotExists)
    {
        return PutBodyStyle(bodystyle);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteBodyStyle(int idBodyStyle) // DELETE
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM bodystyle WHERE idbodystyle=%1")
                      .arg(idBodyStyle));
}

///////////////////////////////////////////////////////////////////////////
///                                Model                                ///
///////////////////////////////////////////////////////////////////////////

Model DataBaseCarServiceDAO::GetModel(int idModel) // SELECT
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM model WHERE idmodel=%1").arg(idModel));

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        int brand_idbrand = query.value(2).toInt();
        int bodystyle_idbodystyle = query.value(3).toInt();
        return Model(id, Name, brand_idbrand, bodystyle_idbodystyle);
    }

    throw std::runtime_error(QString("Incorrect id model : %1").arg(idModel).toStdString());
}

std::vector<Model> DataBaseCarServiceDAO::GetModelName(QString Name) // SELECT many
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM model WHERE naem ilike '%%1%'").arg(Name));
    std::vector<Model> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        int brand_idbrand = query.value(2).toInt();
        int bodystyle_idbodystyle = query.value(3).toInt();
        result.push_back(Model(id, Name, brand_idbrand, bodystyle_idbodystyle));
    }

    return result;
}

std::vector<Model> DataBaseCarServiceDAO::GetModels() // SELECT ALL
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM model"));
    std::vector<Model> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        int brand_idbrand = query.value(2).toInt();
        int bodystyle_idbodystyle = query.value(3).toInt();
        result.push_back(Model(id, Name, brand_idbrand, bodystyle_idbodystyle));
    }

    return result;
}

bool DataBaseCarServiceDAO::PutModel(Model model) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO model(name, brand_idbrand, bodystyle_idbodystyle) VALUES ('%1', '%2', '%3')")
            .arg(model.Name)
            .arg(model.Brand_idBrand)
            .arg(model.BodyStyle_idBodyStyle);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateModel(Model model, bool CreateIfNotExists) // UPDATE
{
    if(!model.idModel)
        return false;

    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE model SET name='%1', brand_idbrand='%2', bodystyle_idbodystyle='%3' WHERE idmodel=%4")
                           .arg(model.Name)
                           .arg(model.Brand_idBrand)
                           .arg(model.BodyStyle_idBodyStyle)
                           .arg(model.idModel));
    if ( ! flag && CreateIfNotExists)
    {
        return PutModel(model);
    }
    else
    {
        return flag;
    }
}

bool DataBaseCarServiceDAO::DeleteModel(int idModel) // DELETE
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM model WHERE idmodel=%1")
                      .arg(idModel));
}

