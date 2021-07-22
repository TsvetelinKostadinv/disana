#pragma once
#include <functional>
#include <string>

namespace disana
{
using ArgumentName = std::string;
using ArgumentValue = double;

class SingleVariableFunction
{
public:
    SingleVariableFunction(const ArgumentName& argName) : argName(argName) {}

    virtual ~SingleVariableFunction() = default;

    const ArgumentName& getArgName() const { return argName; }

    double operator()(double value) const { return evaluation(value); }

protected:
    ArgumentName argName;
    std::function<double(double)> evaluation;
};
}  // namespace disana
