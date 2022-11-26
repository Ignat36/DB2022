#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"

class Client : public Person
{
public:
    Client(QString _lastVisit);
    Client(int _Person_idPerson, QString _lastVisit);

public:
    int Person_idPerson;
    QString LastVisit;
};

#endif // CLIENT_H
