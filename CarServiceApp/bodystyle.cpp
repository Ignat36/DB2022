#include "bodystyle.h"


BodyStyle::BodyStyle(QString _Name) :
    Name(_Name)
{
    idBodyStyle = 0;
}

BodyStyle::BodyStyle(int _idBodyStyle, QString _Name) :
    idBodyStyle(_idBodyStyle), Name(_Name)
{

}
