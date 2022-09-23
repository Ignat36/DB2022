#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"

class Client : public Person
{
public:
    Client();
    Client(QString _FIO, QString _CardNumber, QString _PhoneNumber);

private:
    int Person_idPerson;
};

#endif // CLIENT_H
