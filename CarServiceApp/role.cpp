#include "role.h"

Role::Role(QString _Name) :
    Name(_Name)
{
    idRole = 0;
}

Role::Role(int _idRole, QString _Name) :
    idRole(_idRole), Name(_Name)
{

}
