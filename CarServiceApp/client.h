#ifndef CLIENT_H
#define CLIENT_H

#include <QDate>

class Client
{
public:
    Client(int _Person_idPerson, QDate _lastVisit);

public:
    int Person_idPerson;
    QDate LastVisit;
};

#endif // CLIENT_H
