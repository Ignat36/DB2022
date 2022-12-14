#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QString>
#include <QDate>

class Document
{
public:
    Document(QString _Text, int _WorkedHours, int _CashTransfer_idCashTransfer, int _Car_idCar, QString _AcceptDate, QString _DoneDate, double _Price);
    Document(int _idDocument, QString _Text, int _WorkedHours, int _CashTransfer_idCashTransfer, int _Car_idCar, QString _AcceptDate, QString _DoneDate, double _Price);

    QString toString();

public:
    int idDocument;
    QString Text;
    int WorkedHours;
    int CashTransfer_idCashTransfer;
    int Car_idCar;
    QString AcceptDate;
    QString DoneDate;
    double Price;
};

#endif // DOCUMENT_H
