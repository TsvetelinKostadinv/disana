#pragma once
#include "function.h"
#include "function_impl.h"

#include <memory>
#include "util/disassert.h"

namespace disana
{
SingleVariableFunction operator+(const SingleVariableFunction& lhs,
                                 const SingleVariableFunction& rhs);

class PlusFunction : public virtual SingleVariableFunction
{
public:
    PlusFunction(const SingleVariableFunction& lhs,
                 const SingleVariableFunction& rhs)
        : SingleVariableFunction(
              [=](double value) { return lhs(value) + rhs(value); }),
          lhs(lhs),
          rhs(rhs)
    {
    }
    virtual ~PlusFunction() = default;

    virtual SingleVariableFunction derivative(
        double d = 0.001,
        DerivationType derType =
            DerivationType::DER_TYPE_CENTRAL) const override
    {
        return lhs.derivative(d, derType) + rhs.derivative(d, derType);
    }

protected:
    const SingleVariableFunction lhs;
    const SingleVariableFunction rhs;
};

SingleVariableFunction operator+(const SingleVariableFunction& lhs,
                                 const SingleVariableFunction& rhs)
{
    return PlusFunction(lhs, rhs);
}

SingleVariableFunction operator+(const SingleVariableFunction& lhs,
                                 const double rhs)
{
    return PlusFunction(lhs, Constant(rhs));
}

SingleVariableFunction operator+(const double lhs,
                                 const SingleVariableFunction& rhs)
{
    return PlusFunction(Constant(lhs), rhs);
}
SingleVariableFunction operator*(const SingleVariableFunction& lhs,
                                 const SingleVariableFunction& rhs);

class MultiplicationFunction : public virtual SingleVariableFunction
{
public:
    MultiplicationFunction(const SingleVariableFunction& lhs,
                           const SingleVariableFunction& rhs)
        : SingleVariableFunction(
              [=](double value) { return lhs(value) * rhs(value); }),
          lhs(lhs),
          rhs(rhs)
    {
    }
    virtual ~MultiplicationFunction() = default;

    virtual SingleVariableFunction derivative(
        double d = 0.001,
        DerivationType derType =
            DerivationType::DER_TYPE_CENTRAL) const override
    {
        return lhs.derivative(d, derType) * rhs +
               lhs * rhs.derivative(d, derType);
    }

protected:
    const SingleVariableFunction lhs;
    const SingleVariableFunction rhs;
};

SingleVariableFunction operator*(const SingleVariableFunction& lhs,
                                 const SingleVariableFunction& rhs)
{
    return MultiplicationFunction(lhs, rhs);
}

SingleVariableFunction operator*(const SingleVariableFunction& lhs,
                                 const double rhs)
{
    return MultiplicationFunction(lhs, Constant(rhs));
}

SingleVariableFunction operator*(const double lhs,
                                 const SingleVariableFunction& rhs)
{
    return MultiplicationFunction(Constant(lhs), rhs);
}

SingleVariableFunction operator-(const SingleVariableFunction& lhs,
                                 const SingleVariableFunction& rhs)
{
    return lhs + -1 * rhs;
}

SingleVariableFunction operator-(const SingleVariableFunction& lhs,
                                 const double rhs)
{
    return lhs + -1 * rhs;
}

SingleVariableFunction operator-(const double lhs,
                                 const SingleVariableFunction& rhs)
{
    return lhs + -1 * rhs;
}
}  // namespace disana
