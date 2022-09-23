#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>
#include <QLineEdit>

class Controller
{
public:
    Controller();

private:
    bool isValidName(QString name);
    bool isValidCar(QString car);
    bool isValidDate(QString date);
    bool isValidCarComponent(QString component);
    QString getLine(QLineEdit &view);

public:

    bool searchForWorker(QString Name, std::vector<QString> &strings);
    bool searchForClient(QString Name, std::vector<QString> &strings);
    bool searchForComponent(QString Name, std::vector<QString> &strings);
    bool searchForTransfer(QString Sender, QString Addresser, std::vector<QString> &strings);
    bool searchForWorks(QString ClientName, QString CarName, QString SatartDate, QString EndDate, std::vector<QString> &strings);

    bool createNewClient();
    bool registerNewUser();
    bool deleteUser();
};

#endif // CONTROLLER_H
