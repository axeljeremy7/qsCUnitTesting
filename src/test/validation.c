#include "../include/validation.h"

void init_var(nummber_parts *v)
{
    v->integer_part_len = 0;
    v->decimals_part_len = 0;
    v->f_number = 0;
    v->d_number = 0;
    v->diff = 0;
}

void init_variables(nummber_parts *a, nummber_parts *b, nummber_parts *c, roots_numbers *result)
{
    init_var(a);
    result->a = *a;

    init_var(b);
    result->b = *b;

    init_var(c);
    result->c = *c;
}

void new_line()
{
    printf("\n");
}

void get_precision_details(char *array, int *integer_part_len,
                           int *decimals_part_len, FILE *fp)
{
    size_t len = strlen(array);
    fprintf(fp, "LOG LINE 33: %s strlen(array) => %zu\n", array, len);
    if (len == 0)
    {
        return;
    }
    size_t i = 0;
    int integer_count = 0;
    int decimals_count = 0;
    for (i = 0; i < len; i++)
    {
        // printf("%c, ", array[i]);
        integer_count++;
        if (array[i] == '.')
        {
            break;
        }
    }
    for (i = integer_count; i < len; i++)
    {
        // printf("%c, ", array[i]);
        decimals_count++;
    }
    integer_count--;
    *integer_part_len = integer_count;
    *decimals_part_len = decimals_count;
    fprintf(fp, "Log Line 39: integer_part_len => %d, %d\n",
            integer_count, *integer_part_len);
    fprintf(fp, "Log Line 41:  decimals_part_len => %d, %d\n",
            decimals_count, *decimals_part_len);
}

void get_precision(char *a_array, char *b_array,
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

void show_precision_details(nummber_parts *a, nummber_parts *b, nummber_parts *c){
    printf("\tA\n"); 
    printf("\tFloat value is -> %.*f\n", a->decimals_part_len, a->f_number); 
    printf("\tDouble value is -> %.*lf\n", a->decimals_part_len, a->d_number); 
    printf("\tThe difference is -> %.*lf\n", a->decimals_part_len, a->diff); 
    printf("\n");

    printf("\tB\n"); 
    printf("\tFloat value is -> %.*f\n", b->decimals_part_len, b->f_number); 
    printf("\tDouble value is -> %.*lf\n", b->decimals_part_len, b->d_number); 
    printf("\tThe difference is -> %.*lf\n", b->decimals_part_len, b->diff); 
    printf("\n");

    printf("\tC\n"); 
    printf("\tFloat value is -> %.*f\n", c->decimals_part_len, c->f_number); 
    printf("\tDouble value is -> %.*lf\n", c->decimals_part_len, c->d_number); 
    printf("\tThe difference is -> %.*lf\n", c->decimals_part_len, c->diff); 
    printf("\n");
}

int validate_float(char *array, nummber_parts *n, FILE *fp, char id)
{
    float test = strtof(array, NULL);
    size_t len = strlen(array);
    size_t i;
    int return_value = 1;
    fprintf(fp, "\n\n");
    fprintf(fp, "LINE 86: The float from the string is represented of %c is %f len-> %zu\n", id, test, len);
    // printf("\tThe float value of %c is represented as %f\n", id, test);
    int integer_count = 0;
    int decimals_count = 0;
    int sign = 0;
    int count_e = 0;
    
    for (i = 0; i < len; i++)
    {
        if (array[i] == '.')
        {
            return_value = 1;
            integer_count++;
            break;
        }
        else if (array[i] < 48 || array[i] > 57)
        {
            fprintf(fp, "LOG LINE 80: array[%lu] -> %c \n", i, array[i]);
            if (array[i] == 'e' || array[i] == 'E')
            {
                count_e++;
            }
            else if (array[i] == '-')
            {
                sign++;
            }
            else
            {
                return_value = 2;
                break;
            }
        }
        if (count_e > 1 || sign > 2)
        {
            return_value = 3;
            break;
        }
        integer_count++;
    }

    fprintf(fp, "LOG LINE 121: count_e -> %d\n", count_e);
    fprintf(fp, "LOG LINE 122: sign -> %d\n", sign);
    fprintf(fp, "LOG LINE 123: integer_count -> %d\n", integer_count);

    if (return_value == 1)
    {
        for (i = integer_count; i < len; i++)
        {
            if (count_e > 1)
            {
                return_value = 5;
            }
            if (array[i] == 'e' || array[i] == 'E')
            {
                count_e++;
                continue;
            }
            if (array[i] < 48 || array[i] > 57)
            {
                return_value = 4;
                fprintf(fp, "LOG LINE 137: The input for a is %s, which is invalid.\n", array);
                printf("The input for a is %s, which is invalid.\n", array);
                break;
            }
            
            decimals_count++;
        }
        fprintf(fp, "LOG LINE 142: count_e -> %d\n", count_e);
        fprintf(fp, "LOG LINE 143: sign -> %d\n", sign);
        fprintf(fp, "LOG LINE 143: decimals_count -> %d\n", decimals_count);
        fprintf(fp, "LOG LINE 151: integer_count -> %d\n", integer_count);
    }

    if (return_value == 1)
    {
        if (isnormal(strtof(array, NULL)) > 0)
        {
            n->f_number = strtof(array, NULL);
            n->d_number = strtod(array, NULL);
            fprintf(fp, "LOG LINE 151: integer_count -> %d\n", integer_count);
            n->integer_part_len = integer_count - sign - 1;
            n->decimals_part_len = decimals_count;
            n->diff = n->d_number - n->f_number;
            if (count_e == 1){
                n->contain_e = 1;
                n->decimals_part_len = 32;
            }
            fprintf(fp, "LOG LINE 159:The input for %c is %s is valid.\n",
                    id, array);
        }
        else
        {
            fprintf(fp, "LOG LINE 163: The input for %c is %s which is not normal\n",
                    id, array);
            printf("The input for %c is %s is not normal\n",
                   id, array);
        }
    }
    fprintf(fp, "LOG LINE 171: The return_value %d, 1 means OK\n", return_value);
    return return_value;
}

int validation_floats(char *array_a, char *array_b,
                      char *array_c, nummber_parts *a,
                      nummber_parts *b, nummber_parts *c, FILE *fp)
{
    int r1 = validate_float(array_a, a, fp, 'a');
    int r2 = validate_float(array_b, b, fp, 'b');
    int r3 = validate_float(array_c, c, fp, 'c');
    if (r1 + r2 + r3 != 3)
    {
        return 2;
    }
    fprintf(fp, "Log LINE 197: %d %d %d\n", r1, r2, r3);
    return 1;
}

void add_numbers_to_result(roots_numbers *result, nummber_parts *a,
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
            p_a, result->a.diff, p_a);

    fprintf(fp, "Log Line 159: ");
    fprintf(fp, "For b => String: %s float: ", b_array);
    fprintf(fp, "%0*f double: %0.*lf diff: %0.*lf p: %d\n",
            p_b, result->b.f_number, p_b, result->b.d_number,
            p_b, result->b.diff, p_b);

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
        printf("Equation is not quadratic - 'a' cannot be 0.\n");
        return 0;
    }
    return 1;
}