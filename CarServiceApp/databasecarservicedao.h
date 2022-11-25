#ifndef DATABASECARSERVICEDAO_H
#define DATABASECARSERVICEDAO_H

#include <vector>
#include <string>

#include "QSqlDatabase"
#include "car.h"
#include "person.h"
#include "client.h"
#include "cashaccount.h"
#include "document.h"
#include "transfer.h"
#include "worker.h"
#include "workingequipment.h"
#include "service.h"

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
    ///////////////////////////////////////////////////////////////////////////
    ///                                Car                                  ///
    ///////////////////////////////////////////////////////////////////////////
    Car GetCar(int idCar); // get car with car id
    std::vector<Car> GetCar_Client(int Client_Person_idPerson); // get car with client id

    bool PutCar(Car car); // insert car
    bool UpdateCar(Car car, bool CreateIfNotExists); // update car with car.id if not exists creates it

    bool DeleteCar(int idCar); // delete car
    ///////////////////////////////////////////////////////////////////////////
    ///                                Client                               ///
    ///////////////////////////////////////////////////////////////////////////
    Client GetClient(int Person_idPerson); // get client with client id
    std::vector<Client> GetClient_FIO(std::string FIO); // get client with FIO

    bool PutClient(Client client); // insert client
    bool UpdateClient(Client client, bool CreateIfNotExists); // update client with client.id if not exists creates it

    bool DeleteClinet(int Person_idPerson); // delete client
    ///////////////////////////////////////////////////////////////////////////
    ///                                Worker                               ///
    ///////////////////////////////////////////////////////////////////////////
    Worker GetWorker (int Person_idPerson); // get worker with worker id
    std::vector<Worker> GetWorker_FIO(std::string FIO); // get worker with FIO

    bool PutWorker(Worker worker); // insert worker
    bool UpdateWorker(Worker worker, bool CreateIfNotExists); // update worker with worker.id if not exists creates it

    bool DeleteWorker(int Person_idPerson); // delete worker
    ///////////////////////////////////////////////////////////////////////////
    ///                           WorkingEquipment                          ///
    ///////////////////////////////////////////////////////////////////////////
    WorkingEquipment GetEquipment (int idEquipment); // get equipment with equipment id
    std::vector<WorkingEquipment> GetEquipment_Name(std::string Name); // get equipment with Name

    bool PutEquipment(WorkingEquipment equipment); // insert equipment
    bool UpdateEquipment(WorkingEquipment equipment, bool CreateIfNotExists); // update equipment with equipment.id if not exists creates it

    bool DeleteEquipment(int idEquipment); // delete equipment
    ///////////////////////////////////////////////////////////////////////////
    ///                                Service                              ///
    ///////////////////////////////////////////////////////////////////////////
    Service GetService (int idService); // get service with service id
    std::vector<Service> GetService_Name(std::string Name); // get service with Name

    bool PutService(Service service); // insert service
    bool UpdateService(Service service, bool CreateIfNotExists); // update service with service.id if not exists creates it

    bool DeleteService(int idService); // delete service
    ///////////////////////////////////////////////////////////////////////////
    ///                              CashAccount                            ///
    ///////////////////////////////////////////////////////////////////////////
    CashAccount GetCashAccount (int idCashAccount); // get cashaccount with cashaccount id
    CashAccount GetCashAccount_Number (int CardNumber); // get cashaccount with cashaccount card number

    std::vector<CashAccount> GetCashAccount_idPerson(int Person_idPerson); // get cashaccount with person id

    bool PutCashAccount(CashAccount cashaccount); // insert cashaccount
    bool UpdateCashAccount(CashAccount cashaccount, bool CreateIfNotExists); // update cashaccount with cashaccount.id if not exists creates it

    bool DeleteCashAccount(int idCashAccount); // delete cashaccount
    ///////////////////////////////////////////////////////////////////////////
    ///                             CashTransfer                            ///
    ///////////////////////////////////////////////////////////////////////////
    Transfer GetTransfer (int idTransfer); // get transfer with transfer id

    std::vector<Transfer> GetTransfer_idCashAccount(int CashAccount_idCashAccount); // get transfer with cashaccount id

    bool PutTransfer(Transfer transfer); // insert transfer
    bool UpdateTransfer(Transfer transfer, bool CreateIfNotExists); // update transfer with transfer.id if not exists creates it

    bool DeleteTransfer(int idTransfer); // delete transfer
    ///////////////////////////////////////////////////////////////////////////
    ///                              Document                               ///
    ///////////////////////////////////////////////////////////////////////////
    Document GetDocument (int idDocument); // get document with document id

    std::vector<Document> GetDocument_idTransfer(int CashTransfer_idTransfer); // get document with transfer id
    std::vector<Document> GetDocument_idCar(int Car_idCar); // get document with car id

    bool PutDocument(Document document); // insert document
    bool UpdateDocument(Document document, bool CreateIfNotExists); // update document with document.id if not exists creates it

    bool DeleteDocument(int idDocument); // delete document
    ///////////////////////////////////////////////////////////////////////////
private:
    ///////////////////////////////////////////////////////////////////////////
    ///                                Person                               ///
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///                                Brand                                ///
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///                                BodyStyle                            ///
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///                                Model                                ///
    ///////////////////////////////////////////////////////////////////////////
public:
    ~DataBaseCarServiceDAO(); // disconnect
};

#endif // DATABASECARSERVICEDAO_H
