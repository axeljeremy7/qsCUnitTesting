#include "include/validation.h"

void 
new_line()
{
    printf("\n");
}

void 
get_precision_details(char *array, int *integer_part_len, 
                           int *decimals_part_len, FILE *fp)
{
    size_t len = strlen(array);
    fprintf(fp ,"Log Line 14: %s strlen(array) => %zu\n", array, len);
    if (len == 0)
    {
        return;
    }
    size_t i=0;
    int integer_count = 0;
    int decimals_count = 0;
    for (i=0; i<len; i++)
    {
        // printf("%c, ", array[i]);
        integer_count++;
        if (array[i] == '.')
        {
            break;
        }
    }
    for (i=integer_count; i<len; i++)
    {
        // printf("%c, ", array[i]);
        decimals_count++;
    }
    integer_count--;
    *integer_part_len = integer_count;
    *decimals_part_len = decimals_count;
    fprintf(fp ,"Log Line 39: integer_part_len => %d, %d\n", 
                    integer_count, *integer_part_len);
    fprintf(fp ,"Log Line 41:  decimals_part_len => %d, %d\n", 
                    decimals_count,  *decimals_part_len);
}

void 
get_precision(char *a_array, char *b_array, 
                   char *c_array, nummber_parts *a, 
                   nummber_parts *b, nummber_parts *c, FILE *fp)
{
    get_precision_details(a_array, &(a->integer_part_len),
                          &(a->decimals_part_len), fp);
    get_precision_details(b_array, &(b->integer_part_len), 
                          &(b->decimals_part_len), fp);
    get_precision_details(c_array, &(c->integer_part_len), 
                          &(c->decimals_part_len), fp);
}

int 
validate_float(char *array, nummber_parts *n, FILE *fp, char id)
{
    float test = strtof(array, NULL);
    size_t len = strlen(array);
    size_t i;
    int return_value = 1;
    fprintf (fp, "LINE 65: The float of %c is %f len:%zu\n", id, test, len);

    int integer_count = 0;
    int decimals_count = 0;
    int sign = 0;
    int count_e = 0;
    for (i=0; i<len; i++)
    {
        if (array[i] == '.'){
            return_value = 1;
            integer_count++;
            break;
        }
        else if (array[i] < 48 || array[i] > 57 )
        {   
            // fprintf( fp, "LOG LINE 80:::::: c: %c \n", array[i]);
             if (array[i] == 'e' || array[i] == 'E')
            {
                count_e++;
                // fprintf( fp, "LOG LINE 107:::::: e: %d sign: %d\n", count_e, sign);
            }
            if (array[i] == '-')
            {
                sign++;
            }  
            
            if (count_e > 1)
            {
                return_value = 1;
            }

            if (sign == 1)
            {
                return_value = 1;
            }
            else
            {
                return_value = 2;
                fprintf(fp, "Error Line 90: ");
                fprintf(fp, "The input for a is %s, which is invalid.\n", array);
            }
        }
        integer_count++;
    }
    
    fprintf (fp, "LOG LINE 97: The integer_count plus one %d\n", 
             integer_count);
    for (i=integer_count+1; i<len; i++)
    {
        if (array[i] == 'e' || array[i] == 'E')
        {
            count_e++;
            fprintf(fp, "LOG LINE 107:::::: e: %d sign: %d\n", count_e, sign);
        }

        if (array[i] < 48 || array[i] > 57 )
        {
            return_value = 2;
            fprintf(fp, "Error Line 104: ");
            fprintf(fp, "The input for a is %s, which is invalid.\n", array);
            break;
        }
        decimals_count++;
    }

    if (count_e == 1)
    {
        return_value = 1;
    }

    fprintf(fp, "LOG LINE 107: e: %d sign: %d\n", count_e, sign);
    fprintf (fp, "LOG LINE 98: The decimals_count with or without break %d\n",
             decimals_count);

    if (return_value == 1)
    {
        if (isnormal(strtof(array, NULL)) > 0)
        {
            n->f_number = strtof(array, NULL);
            n->d_number = strtod(array, NULL);
            n->diff = n->d_number - n->f_number;
            fprintf(fp, "Log Line 108: ");
            fprintf(fp, "The input for %c is %s which is valid.\n", 
                                       id,  array);
        }
        else
        {
            fprintf(fp, "Error Line 114: ");
            fprintf(fp, "The input for %c is %s which is not normal\n",
                                       id,  array);
        }
    }
    fprintf (fp, "LOG LINE 119: The return_value %d\n", return_value);
    return return_value;
}

int 
validation_floats(char *array_a, char *array_b, 
                  char *array_c, nummber_parts *a, 
                  nummber_parts *b, nummber_parts *c, FILE *fp)
{
    int r1 = validate_float(array_a, a,  fp, 'a');
    int r2 = validate_float(array_b, b, fp, 'b');
    int r3 = validate_float(array_c, c, fp, 'c');
    if (r1 + r2 + r3 != 3)
    {
        return 2;
    }
    fprintf(fp, "Log LINE 135: %d %d %d\n", r1, r2, r3);
    return 1;
}

void 
add_numbers_to_result(roots_numbers *result, nummber_parts *a, 
                      nummber_parts *b, nummber_parts *c,
                      FILE *fp, char *a_array, char *b_array, 
                      char *c_array)
{
    result->a = *a;
    result->b = *b;
    result->c = *c; 
    // fprintf(fp, "Log LINE 112: %s\n", 
    //    "Checking if passing has been successful"); TODO: LATER TO IMPLEMENT
    int p_a = result->a.decimals_part_len;
    int p_b = result->b.decimals_part_len;
    int p_c = result->c.decimals_part_len;
    fprintf(fp, "Log Line 153: ");
    fprintf(fp, "For a => String: %s float: ", a_array);
    fprintf(fp, "%0.*f double: %0.*lf diff: %0.*lf p: %d\n",
            p_a, result->a.f_number, p_a, result->a.d_number, 
            p_a,result->a.diff, p_a);

    fprintf(fp, "Log Line 159: ");
    fprintf(fp, "For b => String: %s float: ", b_array);
    fprintf(fp, "%0*f double: %0.*lf diff: %0.*lf p: %d\n", 
            p_b, result->b.f_number, p_b, result->b.d_number, 
            p_b,result->b.diff, p_b);

    fprintf(fp, "Log Line 165: ");
    fprintf(fp, "For c => String: %s float: ", c_array);
    fprintf(fp, "%0.*f double: %0.*lf diff: %0.*lf p: %d\n", 
            p_c, result->c.f_number, p_c, result->c.d_number, 
            p_c, result->c.diff, p_c);
    
}

int check_is_quadratic(float a, FILE *fp)
{
    //if a is 0 - equation is not quadratic. Print error
    if (a == (float)0.0)
    {
        fprintf(fp, "ERROR IN LINE 178: ");
        fprintf(fp, "Equation is not quadratic - 'a' cannot be 0.\n");
        return 0;
    }
    return 1;
}