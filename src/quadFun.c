#include "include/header.h"

double 
discrim(float a, float b, float c, FILE *log)
{
    double d;
    d = ((double)b * (double)b) - ((double)4.0* (double)a * (double)c);
    fprintf(log, "FILE: %s LINE: %d  8: d -> %lf\n",  __FILE__,  __LINE__, d);
    return d;
}

int 
check_discrim(double d, FILE *log)
{   
    fprintf(log, "LINE 15: d -> %lf\n", d);
    if (d < 0)
    {
        return 0;
    } 
    else if (d == 0)
    {
        return 1;
    } 
    else 
    {
        return 2;
    } 
}

double 
get_root_minus(float a, float b, float c, double d, FILE *log)
{
    double root;
    root = (-(double)b - sqrt(d)) / (2 * (double)a);
    fprintf(log, "root+ -> %lf\n", root);
    return root;
}

double 
get_root_plus(float a, float b, float c, double d, FILE *log)
{
    double root;
    root = (-(double)b + sqrt(d)) / (2 * (double)a);
    fprintf(log, "root- -> %lf\n", root);
    return root;
}