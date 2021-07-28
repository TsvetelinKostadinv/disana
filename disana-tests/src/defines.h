#pragma once
#include "catch_amalgamated.hpp"

#define REQUIRE_CLOSE(a, b) REQUIRE(std::abs((a) - (b)) < DBL_EPSILON)