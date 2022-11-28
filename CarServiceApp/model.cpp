#include "model.h"


Model::Model(QString _Name, int idBrand, int idBodyStyle) :
    Name(_Name), Brand_idBrand(idBrand), BodyStyle_idBodyStyle(idBodyStyle)
{
    idModel = 0;
}

Model::Model(int _idModel, QString _Name, int idBrand, int idBodyStyle) :
    idModel(_idModel), Name(_Name), Brand_idBrand(idBrand), BodyStyle_idBodyStyle(idBodyStyle)
{

}
