#ifndef SPARECARCOMPONENT_H
#define SPARECARCOMPONENT_H

#include <QString>
#include <QDate>

class Component
{
public:
    Component(QString _Name, QString _Date, double _Price);
    Component(int _idComponent, QString _Name, QString _Date, double _Price);

    QString toString();

public:
    int idComponent;
    QString Name;
    QString DateOfManufacture;
    double Price;
};

#endif // SPARECARCOMPONENT_H
