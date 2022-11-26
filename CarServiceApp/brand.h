#ifndef BRAND_H
#define BRAND_H

#include <QString>

class Brand
{
public:
    Brand(QString _Name);
    Brand(int _idBrand, QString _Name);

public:
    int idBrand;
    QString Name;
};

#endif // BRAND_H
