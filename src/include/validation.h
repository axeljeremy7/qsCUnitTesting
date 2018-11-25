#ifndef VALIDATION_H
#define VALIDATION_H

#include "header.h"
#include "variables.h"

void init_var(nummber_parts *v);
void init_variables(nummber_parts *a, nummber_parts *b, nummber_parts *c, roots_numbers *result);


void new_line();
void show_precision_details(nummber_parts *a, nummber_parts *b, nummber_parts *c);
void get_precision_details(char *array, int *integer_part_len, 
                           int *decimals_part_len, FILE *fp);
void get_precision(char *a_array, char *b_array, 
                   char *c_array, nummber_parts *a, 
                   nummber_parts *b, nummber_parts *c, FILE *fp);
int validate_float(char *array, nummber_parts *n, FILE *fp, char id);
int validation_floats(char *array_a, char *array_b, 
                      char *array_c, nummber_parts *a, 
                      nummber_parts *b, nummber_parts *c, FILE *fp);
void add_numbers_to_result(roots_numbers *result, nummber_parts *a, 
                           nummber_parts *b, nummber_parts *c, FILE *fp, 
                           char *a_array, char *b_array, char *c_array);
int check_is_quadratic(float a, FILE *fp);

// int validation_input(int argc, char const *argv[], float *a, float *b, float *c);
// int check_nan_inf_numbers(int argc, char const *argv[]);

#endif