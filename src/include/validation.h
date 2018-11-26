#ifndef VALIDATION_H
#define VALIDATION_H

#include "header.h"
#include "variables.h"

void init_var(nummber_parts *v);
void init_variables(nummber_parts *a, nummber_parts *b, nummber_parts *c, roots_numbers *result);
void add_abc_to_result(roots_numbers *result, nummber_parts *a,
                           nummber_parts *b, nummber_parts *c,
                           FILE *fp);

void show_precision_details(nummber_parts *a, nummber_parts *b, nummber_parts *c);

int validate_float(char *array, nummber_parts *n, FILE *fp, char id);
int validation_floats(char *array_a, char *array_b, 
                      char *array_c, nummber_parts *a, 
                      nummber_parts *b, nummber_parts *c, FILE *fp);

int check_is_quadratic(float a, FILE *fp);



#endif