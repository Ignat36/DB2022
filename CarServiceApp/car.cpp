#include "car.h"

Car::Car(int _idCar, int _Model_idModel, QString _Defects, int _Client_Person_idPerson) :
    idCar(_idCar), Model_idModel(_Model_idModel), Defects(_Defects), Client_Person_idPerson(_Client_Person_idPerson)
{

}

Car::Car(int _Model_idModel, QString _Defects, int _Client_Person_idPerson) :
    Model_idModel(_Model_idModel), Defects(_Defects), Client_Person_idPerson(_Client_Person_idPerson)
{
    idCar = 0;
}
