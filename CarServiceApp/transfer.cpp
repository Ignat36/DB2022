#include "transfer.h"


Transfer::Transfer(int _idTransfer, double _Cash, int _CashAccount_idCashAccount, QString _Type) :
    idTransfer(_idTransfer), Cash(_Cash), CashAccount_idCashAccount(_CashAccount_idCashAccount), Type(_Type)
{

}

Transfer::Transfer(double _Cash, int _CashAccount_idCashAccount, QString _Type) :
    Cash(_Cash), CashAccount_idCashAccount(_CashAccount_idCashAccount), Type(_Type)
{
    idTransfer = 0;
}
