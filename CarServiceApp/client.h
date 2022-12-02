#ifndef CLIENT_H
#define CLIENT_H

#include <QDate>

class Client
{
public:
    Client(int _Person_idPerson, QString _lastVisit);

public:
    int Person_idPerson;
    QString LastVisit;
};

#endif // CLIENT_H
