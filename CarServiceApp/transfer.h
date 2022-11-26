#ifndef TRANSFER_H
#define TRANSFER_H

#include <QString>

class Transfer
{
public:
    Transfer(int _idTransfer, double _Cash, int _CashAccount_idCashAccount, QString _Type);
    Transfer(double _Cash, int _CashAccount_idCashAccount, QString _Type);

public:
    int idTransfer;
    double Cash;
    int CashAccount_idCashAccount;
    QString Type;
};

#endif // TRANSFER_H
