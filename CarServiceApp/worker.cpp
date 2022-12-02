#include "worker.h"


Worker::Worker(int _Person_idPerson, QString _PersonalQualities, double _Salary, int _UnpaidHours, int _PaidHours, QString _HireDate, QString _Qualification) :
    Person_idPerson(_Person_idPerson), PersonalQualities(_PersonalQualities),
    Salary(_Salary), UnpaidHours(_UnpaidHours), PaidHours(_PaidHours),
    HireDate(_HireDate), Qualification(_Qualification)
{

}
