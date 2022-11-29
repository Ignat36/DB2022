#ifndef SPARECARCOMPONENT_H
#define SPARECARCOMPONENT_H

#include <QString>
#include <QDate>

class Component
{
public:
    Component(QString _Name, QDate _Date, double _Price);
    Component(int _idComponent, QString _Name, QDate _Date, double _Price);

public:
    int idComponent;
    QString Name;
    QDate DateOfManufacture;
    double Price;
};

#endif // SPARECARCOMPONENT_H
