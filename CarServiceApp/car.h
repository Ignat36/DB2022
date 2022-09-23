#ifndef CAR_H
#define CAR_H

#include <QString>
#include <vector>
#include "sparecarcomponent.h"

class Car
{
public:
    Car();
    Car(QString _Brand, QString _Model, QString _BodyStyle);

public:
    void RequestComponent(QString Name);
    void ReportDefect(QString defect, QString date);

private:
    int idCar;
    QString Brand;
    QString Model;
    QString BodyStyle;
    QString Defects;
    std::vector<SpareCarComponent> RequiredComponents;

private:
    int Client_idClint;
};

#endif // CAR_H
