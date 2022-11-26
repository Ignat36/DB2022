#ifndef CASHACCOUNT_H
#define CASHACCOUNT_H

#include <QString>

class CashAccount
{
public:
    CashAccount(double _Cash, QString _CardNumber, int _Person_idPerson);
    CashAccount(int _idCashAccount, double _Cash, QString _CardNumber, int _Person_idPerson);

public:
    int idCashAccount;
    double Cash;
    QString CardNumber;
    int Person_idPerson;
};

#endif // CASHACCOUNT_H
