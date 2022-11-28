#include "brand.h"


Brand::Brand(QString _Name) :
    Name(_Name)
{
    idBrand = 0;
}

Brand::Brand(int _idBrand, QString _Name) :
    idBrand(_idBrand), Name(_Name)
{

}
