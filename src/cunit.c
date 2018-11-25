// cunit.c
// The global constants for cunit and cunit_init(),
// which should be called befoer using the unit test
// macros in cunit.h
#include <stdio.h>
#include "cunit.h"

FILE *cunit_log; // when cunit test macors print resu
double cunit_dmacheps;

int cunit_init()
{
    double dm;
    double dmacheps = 0.5;

    cunit_log = fopen("log_unit_err","w"); ;

    // a crude way for getting close to macheps
    // should use a standard lib cal here
    // 2−52 ≈ 2.22e-16, TO DO LATER
    while ((1.0 + (dm = dmacheps / 2.0)) != 1.0)
    {
        dmacheps = dm;
    }
    cunit_dmacheps = dmacheps;
    return 0;
}
