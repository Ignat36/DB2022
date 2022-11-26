#ifndef WORKINGEQUIPMENT_H
#define WORKINGEQUIPMENT_H

#include <QString>

class WorkingEquipment
{
public:
    WorkingEquipment(QString _Name, QString _AssignmentOfUse, QString _LastUsedDate, double _Price);
    WorkingEquipment(int _idWorkingEquipment, QString _Name, QString _AssignmentOfUse, QString _LastUsedDate, double _Price);

public:
    int idWorkingEquipment;
    QString Name;
    QString AssignmentOfUse;
    QString LastUsedDate;
    double Price;
};

#endif // WORKINGEQUIPMENT_H
