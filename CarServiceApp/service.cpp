#include "service.h"


Service::Service(QString _Description, double _Price, int _RequiredTimeH, QString _Name) :
    Description(_Description), Price(_Price), RequiredTimeH(_RequiredTimeH), Name(_Name)
{
    idService = 0;
}

Service::Service(int _idService, QString _Description, double _Price, int _RequiredTimeH, QString _Name) :
    idService(_idService), Description(_Description), Price(_Price), RequiredTimeH(_RequiredTimeH), Name(_Name)
{

}
