#ifndef SPARECARCOMPONENT_H
#define SPARECARCOMPONENT_H

#include <QString>

class SpareCarComponent
{
public:
    SpareCarComponent();
    SpareCarComponent(QString _Name, QString _Date, int _BuyPrice, int _SellPrice, int _WeightKg);

private:
    int idSpareCarComponent;
    QString Name;
    QString DateOfManufacture;
    int SellPrice;
    int BuyPrice;
    int WeightKg;
};

#endif // SPARECARCOMPONENT_H
