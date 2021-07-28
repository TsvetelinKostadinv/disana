#include "catch_amalgamated.hpp"

#include "defines.h"
#include "function/function.h"
#include "function/function_impl.h"
#include "function/function_op.h"

TEST_CASE("Operation ordering", "[Operations]")
{
    disana::SingleVariableFunction f;
    {
        disana::Identity x;
        f = 2 * x + 3;
    }
    REQUIRE_CLOSE(f(3), 2 * 3 + 3);
}

TEST_CASE("Operation ordering with parentesis", "[Operations]")
{
    disana::SingleVariableFunction f;
    {
        disana::Identity x;
        f = 2 * (x + 3);
    }
    REQUIRE_CLOSE(f(3), 2 * (3 + 3));
}