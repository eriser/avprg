#include <QDebug>
#include <memory>
#include "example.h"
#include "context.h"
#include "strategycontext.h"

void testPointerToObject(){
    qDebug() << ">>> testPointerToObject";
    Example* examplePtr = nullptr;
    examplePtr = new Example("examplePtr");
    examplePtr->method();

    // every new requires delete
    delete examplePtr;
    qDebug() << "<<< testPointerToObject";
}


void testObject(){
    qDebug() << ">>> testObject()";
    Example example("exampleObject");
    example.method();
    qDebug() << "<<< testObject()";
}

void testSmartPointer(){
    qDebug() << ">>> testSmartPointer";
    std::unique_ptr<Example> examplePtr(new Example("example unique_ptr"));
    examplePtr->method();
    // kein delete notwendig
    qDebug() << "<<< testSmartPointer";
}
void testContext(){
    qDebug() << ">>> testContext";
    Context context("context", "example");
    context.contextMethod();
    qDebug() << "<<< testContext";
}
void testStrategyContext(){
    StrategyContext context;
    context.contextMethod();

    auto examplePtr = std::make_shared<Example>("example");
//    std::shared_ptr<Example>examplePtr(new Example("example"));
    context.setAlgorithm(examplePtr);
    context.contextMethod();
}

int main(int argc, char *argv[])
{
    testStrategyContext();
//    testContext();
//    testSmartPointer();
//    testObject();
//    testPointerToObject();
    return 0;
}
