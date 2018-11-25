#ifndef QUADFUN_H
#define QUADFUN_H

#include "header.h"

double discrim(float a, float b, float c, FILE *log);
int check_discrim(double d, FILE *log);
double get_root_minus(float a, float b, float c, double d, FILE *log);
double get_root_plus(float a, float b, float c, double d, FILE *log);

#endif