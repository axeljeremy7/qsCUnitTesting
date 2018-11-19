#include "header.h"

double discrim(float a, float b, float c)
{
    double d;
    d = ((double)b * (double)b) - ((double)4.0* (double)a * (double)c);
    return d;
}
int check_discrim(double d)
{
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
double get_root_minus(float a, float b, float c, double d)
{
    double root;
    root = (-(double)b - sqrt(d)) / (2 * (double)a);
    return root;
}
double get_root_add(float a, float b, float c, double d)
{
    double root;
    root = (-(double)b + sqrt(d)) / (2 * (double)a);
    return root;
}