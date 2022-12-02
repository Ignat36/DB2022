#include "document.h"


Document::Document(QString _Text, int _WorkedHours, int _CashTransfer_idCashTransfer, int _Car_idCar, QString _AcceptDate, QString _DoneDate, double _Price) :
    Text(_Text), WorkedHours(_WorkedHours), CashTransfer_idCashTransfer(_CashTransfer_idCashTransfer),
    Car_idCar(_Car_idCar), AcceptDate(_AcceptDate), DoneDate(_DoneDate), Price(_Price)
{
    idDocument = 0;
}

Document::Document(int _idDocument, QString _Text, int _WorkedHours, int _CashTransfer_idCashTransfer, int _Car_idCar, QString _AcceptDate, QString _DoneDate, double _Price) :
    idDocument(_idDocument), Text(_Text), WorkedHours(_WorkedHours), CashTransfer_idCashTransfer(_CashTransfer_idCashTransfer),
    Car_idCar(_Car_idCar), AcceptDate(_AcceptDate), DoneDate(_DoneDate), Price(_Price)
{

}
