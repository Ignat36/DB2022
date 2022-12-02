#include "workingequipment.h"


WorkingEquipment::WorkingEquipment(QString _Name, QString _AssignmentOfUse, QString _LastUsedDate, double _Price) :
    Name(_Name), AssignmentOfUse(_AssignmentOfUse), LastUsedDate(_LastUsedDate), Price(_Price)
{
    idWorkingEquipment = 0;
}

WorkingEquipment::WorkingEquipment(int _idWorkingEquipment, QString _Name, QString _AssignmentOfUse, QString _LastUsedDate, double _Price) :
    idWorkingEquipment(_idWorkingEquipment), Name(_Name), AssignmentOfUse(_AssignmentOfUse), LastUsedDate(_LastUsedDate), Price(_Price)
{
}

QString WorkingEquipment::toString()
{
    return    QString("   ----------------------------------------------------->")
            + QString("\n       Название       : ") + Name
            + QString("\n       Цена           : ") + QString::number(Price)
            + QString("\n       Назначение     : ") + AssignmentOfUse;
}
