#include <limits>
#include "catch_amalgamated.hpp"

#include "function/function.h"
#include "function/function_impl.h"
#include "function/function_op.h"

#ifdef FULL_TEST
TEST_CASE("The evaluation of the identity is near the actual value",
          "[Identity]")
{
    disana::SingleVariableFunction f("x");
    {
        disana::Identity x("x");
        f = x;
    }
    constexpr double min = std::numeric_limits<double>::min();
    constexpr double max = std::numeric_limits<double>::max();
    constexpr double step = 0.0001;

    for (double i = min; i <= max; i += step)
    {
        REQUIRE(std::fabs(f(i) - i) < DBL_EPSILON);
    }
}
#endif  //  FULL_TEST
