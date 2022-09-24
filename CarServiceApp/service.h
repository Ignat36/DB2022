#ifndef SERVICE_H
#define SERVICE_H

#include <QString>

class Service
{
public:
    Service();
    Service(QString _Description, int _Price, int _RequiredTimeH);

private:
    int idService;
    QString Description;
    int Price;
    int RequiredTimeH;
};

#endif // SERVICE_H
