#pragma once
#include <functional>
#include <string>
#include "util/disassert.h"

namespace disana
{
using ArgumentValue = double;

class SingleVariableFunction
{
public:
    SingleVariableFunction(
        const std::function<double(double)> evaluation =
            [](double value) { return value; })
        : evaluation(evaluation)
    {
    }

    virtual ~SingleVariableFunction() = default;

    enum class DerivationType
    {
        DER_TYPE_FORWARD,
        DER_TYPE_BACKWARD,
        DER_TYPE_CENTRAL,
    };

    double derivative(
        double value,
        double d = 0.001,
        DerivationType derType = DerivationType::DER_TYPE_CENTRAL) const
    {
        switch (derType)
        {
            case DerivationType::DER_TYPE_FORWARD:
                return (evaluation(value) - evaluation(value + d)) / d;
            case DerivationType::DER_TYPE_BACKWARD:
                return (evaluation(value - d) - evaluation(value)) / d;
            case DerivationType::DER_TYPE_CENTRAL:
                return (evaluation(value - d) - evaluation(value + d)) / 2 / d;
            default:  // impossible unless we have missed a case in the
                      // derivation type
                disimpossible("Unrecognised derivation type!");
                return 0.0f;
        }
    }

    virtual SingleVariableFunction derivative(
        double d = 0.001,
        DerivationType derType = DerivationType::DER_TYPE_CENTRAL) const
    {
        switch (derType)
        {
            case DerivationType::DER_TYPE_FORWARD:
                return SingleVariableFunction([=](double value) {
                    return (evaluation(value) - evaluation(value + d)) / d;
                });
            case DerivationType::DER_TYPE_BACKWARD:
                return SingleVariableFunction([=](double value) {
                    return (evaluation(value - d) - evaluation(value)) / d;
                });
            case DerivationType::DER_TYPE_CENTRAL:
                return SingleVariableFunction([=](double value) {
                    return (evaluation(value - d) - evaluation(value + d)) / 2 /
                           d;
                });
            default:  // impossible unless we have missed a case in the
                      // derivation type
                disimpossible("Unrecognised derivation type!");
                return SingleVariableFunction(
                    [=](double value) { return 0.0; });
        }
    }

    double operator()(double value) const { return evaluation(value); }

protected:
    std::function<double(double)> evaluation;
};
}  // namespace disana
