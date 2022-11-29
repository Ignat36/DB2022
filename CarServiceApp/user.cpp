#include "user.h"


User::User(QString _Login, QString _Password, int _Role_idRole) :
    Login(_Login), Password(_Password), Role_idRole(_Role_idRole)
{
    idUser = 0;
}

User::User(int _idUser, QString _Login, QString _Password, int _Role_idRole) :
    idUser(_idUser), Login(_Login), Password(_Password), Role_idRole(_Role_idRole)
{

}
