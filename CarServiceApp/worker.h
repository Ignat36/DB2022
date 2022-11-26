#ifndef WORKER_H
#define WORKER_H

#include "person.h"

class Worker : public Person
{
public:
    Worker(QString _PersonalQualities, double _Salary, int _UnpaidHours, int _PaidHours, QString _HireDate, QString _Qualification);
    Worker(int _Person_idPerson, QString _PersonalQualities, double _Salary, int _UnpaidHours, int _PaidHours, QString _HireDate, QString _Qualification);

public:
    int Person_idPerson;
    QString PersonalQualities;
    double Salary;
    int UnpaidHours;
    int PaidHours;
    QString HireDate;
    QString Qualification;
};

#endif // WORKER_H
