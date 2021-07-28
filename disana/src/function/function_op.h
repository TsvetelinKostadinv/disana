#pragma once
#include "function.h"
#include "function_impl.h"

#include <memory>
#include "util/disassert.h"

namespace disana
{
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
}  // namespace disana
