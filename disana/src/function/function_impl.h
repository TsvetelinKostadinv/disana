#pragma once
#include "function.h"

namespace disana
{
class Constant : public virtual SingleVariableFunction
{
public:
    Constant(double constant)
        : SingleVariableFunction([=](double _) { return constant; }),
          constant(constant)
    {
    }

    virtual ~Constant() = default;

    virtual SingleVariableFunction derivative(
        double d = 0.001,
        DerivationType derType =
            DerivationType::DER_TYPE_CENTRAL) const override
    {
        return Constant(0);
    }

protected:
    const double constant;
};

class Identity : public virtual SingleVariableFunction
{
public:
    Identity() : SingleVariableFunction([](double value) { return value; }) {}

    virtual SingleVariableFunction derivative(
        double d = 0.001,
        DerivationType derType =
            DerivationType::DER_TYPE_CENTRAL) const override
    {
        return Constant(1);
    }

    virtual ~Identity() = default;
};
}  // namespace disana