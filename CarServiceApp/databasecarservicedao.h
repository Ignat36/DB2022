#ifndef DATABASECARSERVICEDAO_H
#define DATABASECARSERVICEDAO_H

#include "QSqlDatabase"


class DataBaseCarServiceDAO
{
public:
    DataBaseCarServiceDAO(); // connect

private:
    bool CreateConnection();
    void CloseConnection();
    void test();

private:
    bool isConnected;
    QSqlDatabase DataBase;

public:
    ~DataBaseCarServiceDAO(); // disconnect
};

#endif // DATABASECARSERVICEDAO_H
