#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(QString _Login, QString _Password, int _Role_idRole);
    User(int _idUser, QString _Login, QString _Password, int _Role_idRole);

public:
    int idUser;
    QString Login;
    QString Password;
    int Role_idRole;
};

#endif // USER_H
