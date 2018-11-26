
#include <stdio.h>
#include "../include/cunit.h"

FILE *cunit_log; 
double cunit_dmacheps;

int cunit_init()
{
    double dm;
    double dmacheps = 0.5;

    cunit_log = stderr;

    while ((1.0 + (dm = dmacheps / 2.0)) != 1.0)
    {
        dmacheps = dm;
    }
    cunit_dmacheps = dmacheps;
    return 0;
}
