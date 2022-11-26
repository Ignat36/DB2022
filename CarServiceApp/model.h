#ifndef MODEL_H
#define MODEL_H

#include "brand.h"
#include "bodystyle.h"

class Model
{
public:
    Model(QString _Name, int idBrand, int idBodyStyle);
    Model(int _idModel, QString _Name);

public:
    int idModel;
    QString Name;
    int Brand_idBrand;
    int BodyStyle_idBodyStyle;
};

#endif // MODEL_H
