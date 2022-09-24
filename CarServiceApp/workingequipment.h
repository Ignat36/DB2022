#ifndef WORKINGEQUIPMENT_H
#define WORKINGEQUIPMENT_H

#include <QString>

class WorkingEquipment
{
public:
    WorkingEquipment();
    WorkingEquipment(QString _Name,
                     QString _description,
                     int _price);

private:
    int idWorkingEquipment();
    QString Name;
    QString AssignmentOfUse;
    QString LastUsedDate;
    int Price;
};

#endif // WORKINGEQUIPMENT_H
