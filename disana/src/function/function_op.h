#pragma once
#include "function.h"
#include "function_impl.h"

#include <cassert>
#include <memory>

namespace disana
{
class PlusFunction : public virtual SingleVariableFunction
{
public:
    PlusFunction(const SingleVariableFunction& lhs,
                 const SingleVariableFunction& rhs)
        : SingleVariableFunction(lhs.getArgName()), lhs(lhs), rhs(rhs)
    {
        assert(lhs.getArgName() == rhs.getArgName() ||
               lhs.getArgName() == "_" ||
               rhs.getArgName() == "_");  // temporary

        evaluation = [=](double value) {
            return lhs(value) + rhs(value);
        };
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
