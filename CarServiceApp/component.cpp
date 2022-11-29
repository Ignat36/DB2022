#include "component.h"


Component::Component(QString _Name, QDate _Date, double _Price) :
    Name(_Name), DateOfManufacture(_Date), Price(_Price)
{
    idComponent = 0;
}

Component::Component(int _idComponent, QString _Name, QDate _Date, double _Price) :
    idComponent(_idComponent), Name(_Name), DateOfManufacture(_Date), Price(_Price)
{

}
