#include "libfoo.h"

#include <stdio.h>

void foo(void)
{
    fprintf(stderr, "==========================\n");
    fprintf(stderr, "Running foo from libfoo.so\n");
    fprintf(stderr, "==========================\n");
}