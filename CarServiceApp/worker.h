#ifndef WORKER_H
#define WORKER_H

#include "person.h"

class Worker : public Person
{
public:
    Worker();
    Worker(QString _FIO, QString _CardNumber, QString _PhoneNumber);

private:
    int Person_idPerson;
    QString PersonalQualities;
    int Salary;
    int UnpaidHours;
    int PaidHours;
    QString HireDate;
    QString Qualification;
};

#endif // WORKER_H
