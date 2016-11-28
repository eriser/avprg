#include <QDebug>
#include "strategycontext.h"

StrategyContext::StrategyContext()
    :examplePtr(nullptr)
{

}

void StrategyContext::contextMethod(){
    if(examplePtr != nullptr){
        examplePtr->method();
    }
    else{
        qDebug() << "algorithm not initialized";
    }
}

void StrategyContext::setAlgorithm(std::shared_ptr<Example> examplePtr){
    this->examplePtr = examplePtr;
}
