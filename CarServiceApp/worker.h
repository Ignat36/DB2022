#ifndef WORKER_H
#define WORKER_H

#include <QDate>

class Worker
{
public:
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
