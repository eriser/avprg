#ifndef STRATEGYCONTEXT_H
#define STRATEGYCONTEXT_H

#include <memory>
#include "example.h"

class StrategyContext
{
public:
    StrategyContext();
    void setAlgorithm(std::shared_ptr<Example> examplePtr);
    void contextMethod();
private:
    std::shared_ptr<Example> examplePtr;
};

#endif // STRATEGYCONTEXT_H
