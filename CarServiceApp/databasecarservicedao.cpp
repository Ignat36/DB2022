#include "databasecarservicedao.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

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
    DataBase.setDatabaseName("CarService");
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
    QSqlQuery query;
    query.exec("SELECT * FROM car");

    while (query.next()) {
            QString name = query.value(0).toString();
            QString salary = query.value(1).toString();
            QMessageBox::information(0, "Fuck niggers" ,name + "\n" + salary,QMessageBox::Ok);// быстрый успех
        }
}
