#include "cashaccount.h"


CashAccount::CashAccount(QString _CardNumber, int _Person_idPerson) :
    CardNumber(_CardNumber), Person_idPerson(_Person_idPerson)
{
    idCashAccount = 0;
}

CashAccount::CashAccount(int _idCashAccount, QString _CardNumber, int _Person_idPerson) :
    idCashAccount(_idCashAccount), CardNumber(_CardNumber), Person_idPerson(_Person_idPerson)
{

}
