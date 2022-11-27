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

Car DataBaseCarServiceDAO::GetCar(int idCar)
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

std::vector<Car> DataBaseCarServiceDAO::GetCar_Client(int Client_Person_idPerson)
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

std::vector<Car> DataBaseCarServiceDAO::GetCars()
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

bool DataBaseCarServiceDAO::PutCar(Car car)
{
    QSqlQuery query;
    QString str = QString("INSERT INTO car(defects, client_person_idperson, model_idmodel) VALUES ('%1', %2, %3)")
            .arg(car.Defects)
            .arg(car.Client_Person_idPerson)
            .arg(car.Model_idModel);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdateCar(Car car, bool CreateIfNotExists)
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

bool DataBaseCarServiceDAO::DeleteCar(int idCar)
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM car WHERE idcar=%1")
                      .arg(idCar));
}

Person DataBaseCarServiceDAO::GetPerson(int idPerson)
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

std::vector<Person> DataBaseCarServiceDAO::GetPersonFIO(QString FIO)
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

std::vector<Person> DataBaseCarServiceDAO::GetPersons()
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

bool DataBaseCarServiceDAO::PutPerson(Person person)
{
    QSqlQuery query;
    QString str = QString("INSERT INTO person(fio, phonenumber, mailadres) VALUES ('%1', '%2', '%3')")
            .arg(person.FIO)
            .arg(person.PhoneNumber)
            .arg(person.MailAdres);
    return query.exec(str);
}

bool DataBaseCarServiceDAO::UpdatePerson(Person person, bool CreateIfNotExists)
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

bool DataBaseCarServiceDAO::DeletePerson(int idPerson)
{
    QSqlQuery query;
    return query.exec(QString("DELETE FROM person WHERE idperson=%1")
                      .arg(idPerson));
}

