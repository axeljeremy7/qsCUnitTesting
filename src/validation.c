#include "include/validation.h"

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

void show_precision_details(nummber_parts *a, nummber_parts *b, nummber_parts *c, double err, FILE *log)
{
    printf("\tA\n");
    printf("\tFloat value is -> %.*f\n", a->decimals_part_len, a->f_number);
    printf("\tDouble value is -> %.*lf\n", a->decimals_part_len, a->d_number);
    printf("\tThe difference is -> %.*lf or %g\n", a->decimals_part_len, a->diff, a->diff);
    relative_error( a->f_number, a->d_number, log, err);
    absolute_error( a->f_number, a->d_number, log, err);
    printf("\n");

    printf("\tB\n");
    printf("\tFloat value is -> %.*f\n", b->decimals_part_len, b->f_number);
    printf("\tDouble value is -> %.*lf\n", b->decimals_part_len, b->d_number);
    printf("\tThe difference is -> %.*lf or %g \n", b->decimals_part_len, b->diff, b->diff);
    relative_error( b->f_number, b->d_number, log, err);
    absolute_error( b->f_number, b->d_number, log, err);
    printf("\n");

    printf("\tC\n");
    printf("\tFloat value is -> %.*f\n", c->decimals_part_len, c->f_number);
    printf("\tDouble value is -> %.*lf\n", c->decimals_part_len, c->d_number);
    printf("\tThe difference is -> %.*lf or %g\n", c->decimals_part_len, c->diff, c->diff);
    relative_error( c->f_number, c->d_number, log, err);
    absolute_error( c->f_number, c->d_number, log, err);
    printf("\n");
}

void relative_error(float a, float b, FILE *log, double rerr)
{
    if (fabs(a - b) / (fabs(a) + fabs(b)) > rerr)
    {
        printf("\t-> %24.16f !>= %24.16f relative error=%10.6e\n", a, b, rerr);
        fprintf(log, "FILE: %s LINE %d: %24.16f !>= %24.16f relative error=%10.6e\n",__FILE__, __LINE__, a, b, rerr);
    }else
    {
        fprintf(log,"FILE: %s LINE %d: rerr -> %g\n", __FILE__, __LINE__, rerr);
    }
}

void absolute_error(float a, float b, FILE *log, double aerr)
{
    if (fabs(a - b) > aerr)
    {
        printf("\t-> %24.16f !>= %24.16f relative error=%10.6e\n", a, b, aerr);
        fprintf(log, "FILE: %s LINE %d: %24.16f !>= %24.16f absolute error=%10.6e\n",__FILE__, __LINE__, a, b, aerr);
    }else 
    {
        fprintf(log,"FILE: %s LINE %d: aerr -> %g\n", __FILE__, __LINE__, aerr);
    }
}

int validate_float(char *array, nummber_parts *n, FILE *fp, char id)
{
    float test = strtof(array, NULL);
    size_t len = strlen(array);
    size_t i;
    int return_value = 1;
    fprintf(fp, "\n\n");
    fprintf(fp, "FILE: %s FUNC: %s LINE: %d:  The float from the string is represented of %c is %f len-> %zu\n", __FILE__, __func__, __LINE__, id, test, len);

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
            fprintf(fp, "FILE: %s FUNC: %s LINE: %d: array[%lu] -> %c \n", __FILE__, __func__, __LINE__, i, array[i]);
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

    fprintf(fp, "FILE: %s FUNC: %s LINE: %d: count_e -> %d\n", __FILE__, __func__, __LINE__, count_e);
    fprintf(fp, "FILE: %s FUNC: %s LINE: %d: sign -> %d\n", __FILE__, __func__, __LINE__, sign);
    fprintf(fp, "FILE: %s FUNC: %s LINE: %d: integer_count -> %d\n", __FILE__, __func__, __LINE__, integer_count);

    if (return_value == 1)
    {
        for (i = integer_count; i < len; i++)
        {
            if (count_e > 1)
            {
                return_value = 5;
                break;
            }
            if (array[i] == 'e' || array[i] == 'E')
            {
                count_e++;
                continue;
            }
            else if (array[i] < 48 || array[i] > 57)
            {
                return_value = 4;
                fprintf(fp, "LOG LINE 137: The input for a is %s, which is invalid.\n", array);
                printf("The input for a is %s, which is invalid.\n", array);
                break;
            }

            decimals_count++;
        }
        fprintf(fp, "FILE: %s FUNC: %s LINE: %d: count_e -> %d\n", __FILE__, __func__, __LINE__, count_e);
        fprintf(fp, "FILE: %s FUNC: %s LINE: %d: sign -> %d\n", __FILE__, __func__, __LINE__, sign);
        fprintf(fp, "FILE: %s FUNC: %s LINE: %d: decimals_count -> %d\n", __FILE__, __func__, __LINE__, decimals_count);
        fprintf(fp, "FILE: %s FUNC: %s LINE: %d: integer_count -> %d\n", __FILE__, __func__, __LINE__, integer_count);
    }

    if (return_value == 1)
    {
        if (isnormal(strtof(array, NULL)) > 0)
        {
            n->f_number = strtof(array, NULL);
            n->d_number = strtod(array, NULL);
            n->integer_part_len = integer_count - sign - 1;
            n->decimals_part_len = decimals_count;
            n->diff = n->d_number - n->f_number;
            if (count_e == 1)
            {
                n->contain_e = 1;
                n->decimals_part_len = 32;
            }
            fprintf(fp, "FILE: %s FUNC: %s LINE: %d: The input for %c is %s is valid.\n",
                    __FILE__, __func__, __LINE__, id, array);
        }
        else
        {
            return_value = 5;
            fprintf(fp, "FILE: %s FUNC: %s LINE: %d: The input for %c is %s which is not normal\n",
                    __FILE__, __func__, __LINE__, id, array);
            printf("The input for %c is %s is not normal\n",
                   id, array);
        }
    }
    fprintf(fp, "FILE: %s FUNC: %s LINE: %d: The return_value %d, 1 means OK\n", __FILE__, __func__, __LINE__, return_value);
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
        printf("Invalid input for the A, B, C float values\n");
        return 2;
    }
    fprintf(fp, "FILE: %s FUNC: %s LINE: %d: %d %d %d\n", __FILE__, __func__, __LINE__, r1, r2, r3);
    return 1;
}

void add_abc_to_result(roots_numbers *result, nummber_parts *a,
                       nummber_parts *b, nummber_parts *c,
                       FILE *fp)
{
    result->a = *a;
    result->b = *b;
    result->c = *c;
}

int check_is_quadratic(float a, FILE *fp)
{
    if (a == (float)0.0)
    {
        fprintf(fp, "ERROR IN LINE 178: ");
        fprintf(fp, "FILE: %s FUNC: %s LINE: %d: Equation is not quadratic - 'a' cannot be 0.\n", __FILE__, __func__, __LINE__);
        printf("Equation is not quadratic - 'a' cannot be 0.\n");
        return 0;
    }
    return 1;
}