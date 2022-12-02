#ifndef CASHACCOUNT_H
#define CASHACCOUNT_H

#include <QString>

class CashAccount
{
public:
    CashAccount(QString _CardNumber, int _Person_idPerson);
    CashAccount(int _idCashAccount, QString _CardNumber, int _Person_idPerson);

    QString toString();

public:
    int idCashAccount;
    QString CardNumber;
    int Person_idPerson;
};

#endif // CASHACCOUNT_H
