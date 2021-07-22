#include <cassert>
#include "function/function.h"
#include "function/function_impl.h"
#include "function/function_op.h"

int main()
{
    disana::SingleVariableFunction f("x");
    {
        disana::Identity x("x");
        f = x + 3;
    }

    assert(std::abs(f(2.0) - (2 + 3)) < DBL_EPSILON);
    assert(std::abs(f(3.0) - (3 + 3)) < DBL_EPSILON);
}