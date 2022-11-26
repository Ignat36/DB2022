#ifndef BODYSTYLE_H
#define BODYSTYLE_H

#include <QString>

class BodyStyle
{
public:
    BodyStyle(QString _Name);
    BodyStyle(int _idBodyStyle, QString _Name);

public:
    int idBodyStyle;
    QString Name;
};

#endif // BODYSTYLE_H
