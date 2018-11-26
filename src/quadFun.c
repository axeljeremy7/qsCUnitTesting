#include "include/header.h"

double 
discrim(float a, float b, float c, FILE *log)
{
    double d;
    d = ((double)b * (double)b) - ((double)4.0* (double)a * (double)c);
    fprintf(log, "FILE: %s FUNC: %s LINE: %d: discrim -> %lf\n",  __FILE__,  __func__ ,  __LINE__, d);
    return d;
}

int 
check_discrim(double d, FILE *log)
{   
    fprintf(log, "FILE: %s FUNC: %s LINE: %d: discrim -> %lf\n",  __FILE__,  __func__ ,  __LINE__, d);
    if (d < 0)
    {
        printf("\tNO REAL ROOTS\n\n");
        return 0;
    } 
    else if (d == 0)
    {
        printf("\tOne real double root found:\n");
        return 1;
    } 
    else 
    {
        printf("\tTwo real double roots found:\n");
        return 2;
    } 
}

double 
get_root_minus(float a, float b, float c, double d, FILE *log)
{
    double root;
    root = (-(double)b - sqrt(d)) / (2 * (double)a);
    fprintf(log, "FILE: %s FUNC: %s LINE: %d root- -> %lf\n",  __FILE__,  __func__ ,  __LINE__, root);
    return root;
}

double 
get_root_plus(float a, float b, float c, double d, FILE *log)
{
    double root;
    root = (-(double)b + sqrt(d)) / (2 * (double)a);
    fprintf(log, "FILE: %s FUNC: %s LINE: %d root+ -> %lf\n",  __FILE__,  __func__ ,  __LINE__, root);
    return root;
}