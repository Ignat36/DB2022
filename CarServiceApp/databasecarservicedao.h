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
#include "user.h"
#include "role.h"


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
    bool GiveSalary();
    bool HireWorker(QString FIO, QString Phone, QString Mail, QString Date, double salary, QString Qualification);
    bool NewClient(QString FIO, QString Phone, QString Mail, QString Date, QString Brand, QString Style, QString Model);

public:
    ///////////////////////////////////////////////////////////////////////////
    ///                                User                                 ///
    ///////////////////////////////////////////////////////////////////////////
    User GetUser(QString Login, QString Password); // get user

    bool PutUser(User user); // insert user
    bool UpdateUser(User user, bool CreateIfNotExists); // update user with user.id if not exists creates it

    bool DeleteUser(int idUser); // delete user
    ///////////////////////////////////////////////////////////////////////////
    ///                                Role                                 ///
    ///////////////////////////////////////////////////////////////////////////
    Role GetRole(int idRole); // get role

    bool PutRole(Role role); // insert role
    bool UpdateRole(Role role, bool CreateIfNotExists); // update role with role.id if not exists creates it

    bool DeleteRole(int idRole); // delete role
    ///////////////////////////////////////////////////////////////////////////
    ///                                Component                            ///
    ///////////////////////////////////////////////////////////////////////////
    Component GetComponent(int idComponent); // get component with component id
    std::vector<Component> GetComponent_Name(QString Name); // get component with client id
    std::vector<Component> GetComponents(); // get all components

    bool PutComponent(Component component); // insert component
    bool UpdateComponent(Component component, bool CreateIfNotExists); // update component with component.id if not exists creates it

    bool DeleteComponent(int idComponent); // delete component
    ///////////////////////////////////////////////////////////////////////////
    ///                                Car                                  ///
    ///////////////////////////////////////////////////////////////////////////
    Car GetCar(int idCar); // get car with car id
    std::vector<Car> GetCar_Client(int Client_Person_idPerson); // get car with client id
    std::vector<Car> GetCars(); // get all cars

    bool PutCar(Car car); // insert car
    bool UpdateCar(Car car, bool CreateIfNotExists); // update car with car.id if not exists creates it

    bool DeleteCar(int idCar); // delete car
    ///////////////////////////////////////////////////////////////////////////
    ///                                Client                               ///
    ///////////////////////////////////////////////////////////////////////////
    Client GetClient(int Person_idPerson); // get client with client id
    std::vector<QString> GetClientsStr(QString Name = ""); // get client with name like name
    std::vector<Client> GetClients(); // get clients

    bool PutClient(Client client); // insert client
    bool UpdateClient(Client client, bool CreateIfNotExists); // update client with client.id if not exists creates it

    bool DeleteClinet(int Person_idPerson); // delete client
    ///////////////////////////////////////////////////////////////////////////
    ///                                Worker                               ///
    ///////////////////////////////////////////////////////////////////////////
    Worker GetWorker (int Person_idPerson); // get worker with worker id
    std::vector<QString> GetWorkersStr(QString Name); // get workers with name like name
    std::vector<Worker> GetWorkers(); // get workers

    bool PutWorker(Worker worker); // insert worker
    bool UpdateWorker(Worker worker, bool CreateIfNotExists); // update worker with worker.id if not exists creates it

    bool DeleteWorker(int Person_idPerson); // delete worker
    ///////////////////////////////////////////////////////////////////////////
    ///                           WorkingEquipment                          ///
    ///////////////////////////////////////////////////////////////////////////
    WorkingEquipment GetEquipment (int idEquipment); // get equipment with equipment id
    std::vector<WorkingEquipment> GetEquipment_Name(QString Name); // get equipment with Name
    std::vector<WorkingEquipment> GetEquipments(); // get all equipment

    bool PutEquipment(WorkingEquipment equipment); // insert equipment
    bool UpdateEquipment(WorkingEquipment equipment, bool CreateIfNotExists); // update equipment with equipment.id if not exists creates it

    bool DeleteEquipment(int idEquipment); // delete equipment
    ///////////////////////////////////////////////////////////////////////////
    ///                                Service                              ///
    ///////////////////////////////////////////////////////////////////////////
    Service GetService (int idService); // get service with service id
    std::vector<Service> GetService_Name(QString Name); // get service with Name
    std::vector<Service> GetServices(); // get all service

    bool PutService(Service service); // insert service
    bool UpdateService(Service service, bool CreateIfNotExists); // update service with service.id if not exists creates it

    bool DeleteService(int idService); // delete service
    ///////////////////////////////////////////////////////////////////////////
    ///                              CashAccount                            ///
    ///////////////////////////////////////////////////////////////////////////
    CashAccount GetCashAccount (int idCashAccount); // get cashaccount with cashaccount id
    CashAccount GetCashAccount_Number (QString CardNumber); // get cashaccount with cashaccount card number

    std::vector<CashAccount> GetCashAccount_idPerson(int Person_idPerson); // get cashaccount with person id
    std::vector<CashAccount> GetCashAccounts(); // get all cashaccount
    std::vector<QString> GetCashAccountsStr(QString Name = ""); // get all cashaccount

    bool PutCashAccount(CashAccount cashaccount); // insert cashaccount
    bool UpdateCashAccount(CashAccount cashaccount, bool CreateIfNotExists); // update cashaccount with cashaccount.id if not exists creates it

    bool DeleteCashAccount(int idCashAccount); // delete cashaccount
    ///////////////////////////////////////////////////////////////////////////
    ///                             CashTransfer                            ///
    ///////////////////////////////////////////////////////////////////////////
    Transfer GetTransfer (int idTransfer); // get transfer with transfer id

    std::vector<Transfer> GetTransfer_idCashAccount(int CashAccount_idCashAccount); // get transfer with cashaccount id
    std::vector<Transfer> GetTransfers(); // get all transfer
    std::vector<QString> GetTransfersStr(QString FIO); // get transfers
    std::vector<QString> GetTransfersStr(QString FIO, QString type); // get transfers

    bool PutTransfer(Transfer transfer); // insert transfer
    bool UpdateTransfer(Transfer transfer, bool CreateIfNotExists); // update transfer with transfer.id if not exists creates it

    bool DeleteTransfer(int idTransfer); // delete transfer
    ///////////////////////////////////////////////////////////////////////////
    ///                              Document                               ///
    ///////////////////////////////////////////////////////////////////////////
    Document GetDocument (int idDocument); // get document with document id

    std::vector<Document> GetDocument_idTransfer(int CashTransfer_idTransfer); // get document with transfer id
    std::vector<Document> GetDocument_idCar(int Car_idCar); // get document with car id
    std::vector<Document> GetDocuments(); // get all documents
    std::vector<QString> GetDocumentsStr(QString FIO = "", QString car = "", QString begDate = "", QString endDate = ""); // get documents
    std::vector<QString> GetAllDocumentsStr(); // get documents

    bool PutDocument(Document document); // insert document
    bool UpdateDocument(Document document, bool CreateIfNotExists); // update document with document.id if not exists creates it

    bool DeleteDocument(int idDocument); // delete document




private:
    ///////////////////////////////////////////////////////////////////////////
    ///                                Person                               ///
    ///////////////////////////////////////////////////////////////////////////
    Person GetPerson(int idPerson); // get person with person id
    std::vector<Person> GetPersonFIO(QString FIO); // get person with FIO
    std::vector<Person> GetPersons(); // get all persons

    bool PutPerson(Person person); // insert person
    bool UpdatePerson(Person person, bool CreateIfNotExists); // update person with person.id if not exists creates it

    bool DeletePerson(int idPerson); // delete person
    ///////////////////////////////////////////////////////////////////////////
    ///                                Brand                                ///
    ///////////////////////////////////////////////////////////////////////////
    Brand GetBrand(int idBrand); // get brand with brand id
    std::vector<Brand> GetBrandName(QString Name); // get brand with Name
    std::vector<Brand> GetBrands(); // get all brands

    bool PutBrand(Brand brand); // insert brand
    bool UpdateBrand(Brand brand, bool CreateIfNotExists); // update brand with brand.id if not exists creates it

    bool DeleteBrand(int idBrand); // delete brand
    ///////////////////////////////////////////////////////////////////////////
    ///                                BodyStyle                            ///
    ///////////////////////////////////////////////////////////////////////////
    BodyStyle GetBodyStyle(int idBodyStyle); // get bodystyle with bodystyle id
    std::vector<BodyStyle> GetBodyStyleName(QString Name); // get bodystyle with Name
    std::vector<BodyStyle> GetBodyStyles(); // get all bodystyles

    bool PutBodyStyle(BodyStyle bodystyle); // insert bodystyle
    bool UpdateBodyStyle(BodyStyle bodystyle, bool CreateIfNotExists); // update bodystyle with bodystyle.id if not exists creates it

    bool DeleteBodyStyle(int idBodyStyle); // delete bodystyle
    ///////////////////////////////////////////////////////////////////////////
    ///                                Model                                ///
    ///////////////////////////////////////////////////////////////////////////
    Model GetModel(int idModel); // get model with model id
    std::vector<Model> GetModelName(QString Name); // get model with Name
    std::vector<Model> GetModels(); // get all models

    bool PutModel(Model model); // insert model
    bool UpdateModel(Model model, bool CreateIfNotExists); // update model with model.id if not exists creates it

    bool DeleteModel(int idModel); // delete model





public:
    ~DataBaseCarServiceDAO(); // disconnect
};



#endif // DATABASECARSERVICEDAO_H
