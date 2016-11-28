#ifndef CONTEXT_H
#define CONTEXT_H
#include <QString>
#include <memory>
#include "example.h"



class Context
{
public:
    Context(const QString& contextName, const QString& name);
    ~Context();
    void contextMethod();
private:
    QString contextName;
    Example example;
};


/*
class Context
{
public:
    Context(const QString& contextName, const QString& name);
    ~Context();
    void contextMethod();
private:
    QString contextName;
    std::shared_ptr<Example> examplePtr;
};
*/
#endif // CONTEXT_H
