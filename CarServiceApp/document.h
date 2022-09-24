#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QString>

class Document
{
public:
    Document();
    Document(int _WorkedHours, QString _date);

    bool endWork(QString date);

private:
    int idDocument;
    QString Text;
    int WorkedHours;
    int CashTransfer_idCashTransfer;
    int Client_idClient;
    QString AcceptDate;
    QString DoneDate;
};

#endif // DOCUMENT_H
