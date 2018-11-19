

#ifndef VALIDATION_H
#define VALIDATION_H

#include "header.h"

int validation_input(int argc, char const *argv[], float *a, float *b, float *c);
int check_nan_inf_numbers(int argc, char const *argv[]);

#endif