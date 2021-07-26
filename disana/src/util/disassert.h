#pragma once
#include <cassert>
#include <iostream>

void __disassert(const char* expr_str,
                 bool expr,
                 const char* file,
                 int line,
                 const char* msg)
{
    if (!expr)
    {
        std::cerr << "Assert failed:\t" << msg << "\n"
                  << "Expected:\t" << expr_str << "\n"
                  << "Source:\t\t" << file << ", " << line << "\n";
        abort();
    }
}

#ifdef DISANA_DEBUG
#define disassert(expr, msg) __disassert(#expr, expr, __FILE__, __LINE__, msg)
#define disimpossible(msg) __disassert("", false, __FILE__, __LINE__, msg)
#else
#define disassert(Expr, Msg) ;
#define disimpossible(msg) ;
#endif  // DISANA_DEBUG
