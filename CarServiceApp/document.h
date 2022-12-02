#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QString>
#include <QDate>

class Document
{
public:
    Document(QString _Text, int _WorkedHours, int _CashTransfer_idCashTransfer, int _Car_idCar, QDate _AcceptDate, QDate _DoneDate, double _Price);
    Document(int _idDocument, QString _Text, int _WorkedHours, int _CashTransfer_idCashTransfer, int _Car_idCar, QDate _AcceptDate, QDate _DoneDate, double _Price);

    QString toString();

public:
    int idDocument;
    QString Text;
    int WorkedHours;
    int CashTransfer_idCashTransfer;
    int Car_idCar;
    QDate AcceptDate;
    QDate DoneDate;
    double Price;
};

#endif // DOCUMENT_H
