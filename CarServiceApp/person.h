#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    Person();
    Person(QString _FIO, QString _CardNumber, QString _PhoneNumber);

private:
    int idPerson;
    QString FIO;
    QString CardNumber;
    QString PhoneNumber;
    QString MailAdres;
};

#endif // PERSON_H
