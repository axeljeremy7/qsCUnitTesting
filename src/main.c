#include "include/main.h"

// main this for stdin
// other_file for testing
// I think my internet crashed
// or atleast discord crashed

void init_var(nummber_parts *v);
int memory_ok(Line *linein, FILE *log);
int solve_equation_yes_no(FILE *log);
// int validator_abc(Line *linein, FILE *log, char *a_array, char *b_array, char *c_array, nummber_parts *a, nummber_parts *b, nummber_parts *c, roots_numbers *result);
int main(int argc, char const *argv[])
{
    FILE *log;
    printf("PASS LINE 7\n");
    log = stderr; //fopen("logs/user_logs.txt", "w");

    // char a_array[512], b_array[512], c_array[512];
    // roots_numbers result;

    // double d;
    // int numRoots;
    // nummber_parts a, b, c;
    Line linein;
    linein.max = NLINE;
    // Line linein2;
    // linein2.str = malloc(NLINE);
    // linein2.max = NLINE;

    int returnValue = 0; // 0 means OK

    // int rv;

    if (memory_ok(&linein, log) == 1)
    {
        fprintf(log, "PASS LINE 17\n");
        if (solve_equation_yes_no(log) == 1)
        {
            fprintf(log, "PASS LINE 31\n");
            // printf("Input a b c :");
            fprintf(log, "=> %s\n", linein.str);
            fprintf(log, "=> %d\n", linein.max);
            // fprintf(log, "Input a b c :\n");
            printf("Input A B C :\n");
            if (fgets(linein.str, linein.max, stdin) == NULL)
            {
                fprintf(stderr, "Input error: can not read from stdin\n");
                returnValue = -1;
            }else {
                fprintf(log, "OK    %s", linein.str);

            }

            


            // rv = validator_abc(&linein, log, a_array, b_array, c_array, &a, &b, &c, &result);
            // fprintf(log, "RV=> %d\n", rv);
            fprintf(log, "PASS LINE 35\n");
            free(linein.str);
            fprintf(log, "PASS LINE 37\n");
        }
        else
        {
            returnValue = -1;
        }

        free(linein.str);
    }
    else
    {
        returnValue = -1;
    }

    fclose(log);
    // printf("\n:::::: %s %f\n"," 3.4e4" ,strtof("3.4e4",NULL));
    new_line();

    return returnValue;
}

void init_var(nummber_parts *v)
{
    v->integer_part_len = 0;
    v->decimals_part_len = 0;
    v->f_number = 0;
    v->d_number = 0;
    v->diff = 0;
}

int memory_ok(Line *linein, FILE *log)
{
    if ( (linein->str = malloc(NLINE)) == NULL)
    {
        fprintf(log, "SYSTEM Systems failure no memory for malloc(%d)\n", NLINE);
        return 0;
    }
    linein->len = 0;
    linein->code = -1;
    // linein->str = '\0';
    fprintf(log, "SYSTEM Systems is ok for memory of malloc(%d)\n", NLINE);
    return 1;
}

int solve_equation_yes_no(FILE *log)
{
    char response[2]; // User response: "Y" or "N"
    // response[0] = '\0';
    // response[1] = '\0';
    printf("Do you want to solve a quadratic eqauation Ax^2 + Bx + B = 0 ? (Y/N):");
    if (fgets(response, 2, stdin) == NULL)
    {
        fprintf(log, "SYSTEM Input error: can not read from stdin\n");
        return -1;
    }
    fprintf(log, "SYSTEM obtained response -> %s\n", response);
    fprintf(log, "SYSTEM  response[0] -> %c\n", response[0]);
    fprintf(log, "SYSTEM  response[1] -> %c\n", response[1]);
    if (strncmp(response, "Y", 1) == 0)
    {
        fprintf(log, "SYSTEM -> Response Y\n");
        return 1;
    }
    else if (strncmp(response, "N", 1) == 0)
    {
        fprintf(log, "SYSTEM -> Response N\n");
        return 0;
    }
    else
    {
        fprintf(log, "SYSTEM Input error: response must be a single character: Y or N\n");
        return -1;
    }
}

// int validator_abc(Line *linein, FILE *log, char *a_array, char *b_array, char *c_array, nummber_parts *a, nummber_parts *b, nummber_parts *c, roots_numbers *result)
// {
    
//     fprintf(log, "PASS 116 %d\n", linein->max);
//     fprintf(log, "PASS 117 %d %s\n", linein->max,  linein->str);

//     if (fgets(linein->str, linein->max, stdin) == NULL)
//     {
//         fprintf(log, "SYSTEM Input error: can not read from stdin\n");
//         return -1;
//     }
//     else
//     {
//         double discriminant;
//         int numRoots;
//         while (sscanf(linein->str, "%s %s %s", a_array, b_array, c_array) == 3)
//         {
//             init_var(a);
//             result->a = *a;

//             init_var(b);
//             result->b = *b;

//             init_var(c);
//             result->c = *c;

//             printf("==> %s %s %s\n", a_array, b_array, c_array);
//             fprintf(log, "\nMAIN ==> %s %s %s\n", a_array, b_array, c_array);
//             if (validation_floats(a_array, b_array, c_array, a, b, c, log) == 1)
//             {
//                 get_precision(a_array, b_array, c_array, a, b, c, log);
//                 add_numbers_to_result(result, a, b, c, log,
//                                       a_array, b_array, c_array);

//                 /*printf("\n\ta == %f", result.a.f_number);
//             printf(" | b == %f", result.b.f_number);
//             printf(" | c == %f\n\n", result.c.f_number);*/

//                 if (check_is_quadratic(result->a.f_number, log) == 1)
//                 {
//                     discriminant = discrim(result->a.f_number,
//                                            result->b.f_number,
//                                            result->c.f_number);
//                     numRoots = check_discrim(discriminant);
//                     if (numRoots == 0)
//                     {
//                         printf("\tNO REAL ROOTS\n\n");
//                     }
//                     else if (numRoots == 1)
//                     {
//                         double dblRoot;
//                         dblRoot = get_root_minus(result->a.f_number,
//                                                  result->b.f_number,
//                                                  result->c.f_number, discriminant);
//                         printf("One real double root found:");
//                         printf("\n\tRoot at: %lf\n\n", dblRoot);
//                     }
//                     else
//                     {
//                         result->root_x1 = get_root_minus(result->a.f_number,
//                                                          result->b.f_number,
//                                                          result->c.f_number, discriminant);
//                         result->root_x2 = get_root_plus(result->a.f_number,
//                                                         result->b.f_number,
//                                                         result->c.f_number, discriminant);
//                         printf("Two real double roots found:");
//                         printf("\n\tRoots at: %lf & %lf\n\n",
//                                result->root_x1, result->root_x2);
//                     }
//                     return 1;
//                 }
//                 else
//                 {
//                     printf("\tNOT QUADRATIC\n\n");
//                     return 0;
//                 }
//             }
//             else
//             {
//                 printf("\tINVALID\n\n");
//                 return -1;
//             }
//         }
//         return -1;
//     }
// }
