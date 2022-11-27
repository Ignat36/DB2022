#ifndef CAR_H
#define CAR_H

#include <QString>
#include <vector>
#include "sparecarcomponent.h"
#include "model.h"

class Car
{
public:
    Car(int _idCar, int _Model_idModel, QString _Defects, int _Client_Person_idPerson);
    Car(int _Model_idModel, QString _Defects, int _Client_Person_idPerson);

public:
    int idCar = 0;
    int Model_idModel;
    QString Defects;
    int Client_Person_idPerson;
};

#endif // CAR_H
