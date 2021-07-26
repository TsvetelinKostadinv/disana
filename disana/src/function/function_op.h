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
              lhs.getArgName(),
              [=](double value) { return lhs(value) + rhs(value); }),
          lhs(lhs),
          rhs(rhs)
    {
        disassert(lhs.getArgName() == rhs.getArgName() ||
                      lhs.getArgName() == "_" || rhs.getArgName() == "_",
                  "The functions have to have the same argument or be "
                  "constant");  // temporary
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
