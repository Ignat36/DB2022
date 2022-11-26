#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    Person(QString _FIO, QString _PhoneNumber, QString _MailAdres);
    Person(int _idPerson, QString _FIO, QString _PhoneNumber, QString _MailAdres);

public:
    int idPerson;
    QString FIO;
    QString PhoneNumber;
    QString MailAdres;
};

#endif // PERSON_H
