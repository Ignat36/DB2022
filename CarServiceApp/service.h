#ifndef SERVICE_H
#define SERVICE_H

#include <QString>

class Service
{
public:
    Service(QString _Description, double _Price, int _RequiredTimeH, QString _Name);
    Service(int _idService, QString _Description, double _Price, int _RequiredTimeH, QString _Name);

    QString toString();

public:
    int idService;
    QString Description;
    double Price;
    int RequiredTimeH;
    QString Name;
};

#endif // SERVICE_H
