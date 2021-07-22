#pragma once
#include "function.h"

namespace disana
{
class Constant : public virtual SingleVariableFunction
{
public:
    Constant(double constant) : SingleVariableFunction("_"), constant(constant)
    {
        evaluation = [=](double _) { return constant; };
    }
    virtual ~Constant() = default;

protected:
    const double constant;
};

class Identity : public virtual SingleVariableFunction
{
public:
    Identity(const ArgumentName& argName) : SingleVariableFunction(argName)
    {
        evaluation = [](double value) { return value; };
    }
    virtual ~Identity() = default;
};
}  // namespace disana