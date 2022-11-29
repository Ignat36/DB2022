#ifndef ROLE_H
#define ROLE_H

#include <QString>

class Role
{
public:
    Role(QString _Name);
    Role(int _idRole, QString _Name);

public:
    int idRole;
    QString Name;
};

#endif // ROLE_H
