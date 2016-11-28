#include <QDebug>
#include "context.h"

Context::Context(const QString& contextName, const QString& name)
    : contextName(contextName)
    , example(name) // muss hier initialisiert werden
{
    qDebug() << "constructor Context";
}

Context::~Context(){
    qDebug() << "destructor Context";
    // Destruktor von Example wird hier aufgerufen
}

void Context::contextMethod(){
    qDebug() << "contextMethod()";
    example.method();
}

/*
Context::Context(const QString& contextName, const QString& name)
    : contextName(contextName)
    , examplePtr(new Example(name))
{
    qDebug() << "constructor Context";
}

Context::~Context(){
//    delete examplePtr;
    qDebug() << "destructor Context";
}

void Context::contextMethod(){
    examplePtr->method();
    qDebug() << "contextMethod()";
}
*/
