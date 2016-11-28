#include <QDebug>
#include "example.h"

Example::Example(const QString& name)
    : name(name)
{
    qDebug() << "Constructor Example, name=" << name;
}

Example::~Example(){
    qDebug() << "Destructor Example, name=" << name;
}

void Example::method(){
    qDebug() << "calling method() of Example, name=" << name;
}
