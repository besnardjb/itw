#include "libfoo.h"

#include <iostream>


void foo(void)
{
    std::cerr << "==========================\n";
    std::cerr << "Running foo from libfoo.so\n";
    std::cerr << "==========================\n";
}