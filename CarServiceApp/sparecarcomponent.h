#ifndef SPARECARCOMPONENT_H
#define SPARECARCOMPONENT_H

#include <QString>

class SpareCarComponent
{
public:
    SpareCarComponent(QString _Name, QString _Date, int _Price);
    SpareCarComponent(int _idSpareCarComponent, QString _Name, QString _Date, int _Price);

public:
    int idSpareCarComponent;
    QString Name;
    QString DateOfManufacture;
    double Price;
};

#endif // SPARECARCOMPONENT_H
