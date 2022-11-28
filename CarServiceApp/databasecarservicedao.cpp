#include "databasecarservicedao.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <exception>
#include <QDebug>

// Create connection
DataBaseCarServiceDAO::DataBaseCarServiceDAO() : isConnected(false)
{
    CreateConnection();
    test();
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
        QMessageBox::critical(0,"Cannot open database",
                                      "Unable to establish a database connection.",QMessageBox::Cancel);// вывести ошибку
        qDebug()<<DataBase.lastError().text();// Вывод сообщения об ошибке

        return false;
    }

    QMessageBox::information(0,"Successfully","Establish a database connection",QMessageBox::Ok);// быстрый успех
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
    if (!PutPerson(Person("ignat shar", "1", "none")))
        qDebug()<<"error\n";
    if (!PutPerson(Person("egor penis", "2", "none")))
        qDebug()<<"error\n";
    if (!PutPerson(Person("vanya kar", "3", "none")))
        qDebug()<<"error\n";
    if (!PutPerson(Person("roma kez", "4", "none")))
        qDebug()<<"error\n";
    if (!PutPerson(Person("igor anal", "5", "none")))
        qDebug()<<"error\n";
    if (!PutPerson(Person("lexa akusher", "6", "none")))
        qDebug()<<"error\n";

    std::vector<Person> cl_one = GetPersonFIO("a");
    std::vector<Person> cl_two = GetPersonFIO("g");
    std::vector<Person> cl_fore = GetPersonFIO("ig");

    Person one = GetPerson(cl_one.front().idPerson);
    one.PhoneNumber = "+375293555104";
    UpdatePerson(one, false);

    std::vector<Person> all = GetPersons();

    for(auto i: all)
        DeletePerson(i.idPerson);
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
        QDate LastVisit = query.value(1).toDate();
        return Client(id, LastVisit);
    }

    throw std::runtime_error(QString("Incorrect id Client : %1").arg(Person_idPerson).toStdString());
}

std::vector<Client> DataBaseCarServiceDAO::GetClients() // SELECT ALL
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM client"));
    std::vector<Client> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QDate LastVisit = query.value(1).toDate();
        result.push_back(Client(id, LastVisit));
    }

    return result;
}

bool DataBaseCarServiceDAO::PutClient(Client client) // INSERT
{
    QSqlQuery query;
    QString str = QString("INSERT INTO client(person_idperson, lastvisit) VALUES (%1, '%2')")
            .arg(client.Person_idPerson)
            .arg(client.LastVisit.toString());
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateClient(Client client, bool CreateIfNotExists) // UPDATE
{
    QSqlQuery query;
    bool flag = query.exec(QString("UPDATE client SET lastvisit='%1' WHERE person_idperson=%2")
                           .arg(client.LastVisit.toString())
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
        QDate HireDate = query.value(1).toDate();
        int UnpaidHours = query.value(2).toInt();
        int PaidHours = query.value(3).toInt();
        QString Qualification = query.value(4).toString();
        QString PersonalQualities = query.value(5).toString();
        int id = query.value(6).toInt();
        return Worker(id, PersonalQualities, Salary, UnpaidHours, PaidHours, HireDate, Qualification);
    }

    throw std::runtime_error(QString("Incorrect id Worker : %1").arg(Person_idPerson).toStdString());
}

std::vector<Worker> DataBaseCarServiceDAO::GetWorkers() // SELECT ALL
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM worker"));
    std::vector<Worker> result;

    while (query.next()) {
        double Salary = query.value(0).toDouble();
        QDate HireDate = query.value(1).toDate();
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
            .arg(worker.HireDate.toString())
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
                           .arg(worker.HireDate.toString())
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
        QDate LastUsedDate = query.value(3).toDate();
        double Price = query.value(4).toDouble();
        return WorkingEquipment(id, Name, AssignmentOfUse, LastUsedDate, Price);
    }

    throw std::runtime_error(QString("Incorrect id Equipment : %1").arg(idEquipment).toStdString());
}

std::vector<WorkingEquipment> DataBaseCarServiceDAO::GetEquipment_Name(QString Name)
{
    QSqlQuery query;
    query.exec(QString("SELECT * FROM workingequipment WHERE name like '%%1%'").arg(Name));
    std::vector<WorkingEquipment> result;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString Name = query.value(1).toString();
        QString AssignmentOfUse = query.value(2).toString();
        QDate LastUsedDate = query.value(3).toDate();
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
        QDate LastUsedDate = query.value(3).toDate();
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
            .arg(equipment.LastUsedDate.toJulianDay())
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
                           .arg(equipment.LastUsedDate.toJulianDay())
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
    query.exec(QString("SELECT * FROM person WHERE fio like '%%1%'").arg(FIO));
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

