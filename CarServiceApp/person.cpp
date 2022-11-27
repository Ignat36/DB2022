#include "person.h"


Person::Person(QString _FIO, QString _PhoneNumber, QString _MailAdres) :
    FIO(_FIO), PhoneNumber(_PhoneNumber), MailAdres(_MailAdres)
{
    idPerson = 0;
}

Person::Person(int _idPerson, QString _FIO, QString _PhoneNumber, QString _MailAdres) :
    idPerson(_idPerson), FIO(_FIO), PhoneNumber(_PhoneNumber), MailAdres(_MailAdres)
{

}
