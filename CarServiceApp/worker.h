#ifndef WORKER_H
#define WORKER_H

#include <QDate>

class Worker
{
public:
    Worker(int _Person_idPerson, QString _PersonalQualities, double _Salary, int _UnpaidHours, int _PaidHours, QDate _HireDate, QString _Qualification);

public:
    int Person_idPerson;
    QString PersonalQualities;
    double Salary;
    int UnpaidHours;
    int PaidHours;
    QDate HireDate;
    QString Qualification;
};

#endif // WORKER_H
