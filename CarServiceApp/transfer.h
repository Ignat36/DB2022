#ifndef TRANSFER_H
#define TRANSFER_H

#include <QString>

class Transfer
{
public:
    Transfer();
    Transfer(int _ToCard,
             int _FromCard,
             int _Cash,
             QString _Sender,
             QString _Addresser);

private:
    int idTransfer;
    int ToCardId;
    int FromCardId;
    int Cash;
    QString Sender;
    QString Addresser;
    int ToCashAccount_idCashAccount;
    int FromCashAccount_idCashAccount;
};

#endif // TRANSFER_H
