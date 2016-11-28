#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QString>

class Example
{
public:
    Example(const QString& name);
    ~Example();
    void method();
private:
    QString name;
};

#endif // EXAMPLE_H
