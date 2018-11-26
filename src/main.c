#include "include/main.h"

int solve_equation_yes_no(FILE *log, char *response);

int read_abc(FILE *log, char *a_array, char *b_array, char *c_array, char *response);
int exit_main(FILE *log, char *response);

int main(int argc, char const *argv[])
{
    FILE *log;
    log = stderr; //fopen("logs/user_logs.txt", "w");

    char a_array[128], b_array[128], c_array[128];
    char response[2];

    roots_numbers result;
    nummber_parts a, b, c;
    double discriminant;
    int numRoots;
 

    while (1)
    {
        if (solve_equation_yes_no(log, response) == 1)
        {
            if (read_abc(log, a_array, b_array, c_array, response) == 1)
            {
                init_variables(&a, &b, &c, &result);
                if (validation_floats(a_array, b_array, c_array, &a, &b, &c, log) == 1)
                {
                    add_abc_to_result(&result, &a, &b, &c, log);
                    show_precision_details(&(result.a), &(result.b), &(result.c));
                    if (check_is_quadratic(result.a.f_number, log) == 1)
                    {
                        discriminant = discrim(result.a.f_number,
                                               result.b.f_number,
                                               result.c.f_number, log);
                        numRoots = check_discrim(discriminant, log);
                
                        if (numRoots > 0)
                        {
                            result.root_x1 = get_root_minus(result.a.f_number,
                                                             result.b.f_number,
                                                             result.c.f_number, discriminant,log);
                            result.root_x2 = get_root_plus(result.a.f_number,
                                                            result.b.f_number,
                                                            result.c.f_number, discriminant, log);
                            
                            printf("\n\tRoots at: %lf & %lf\n\n",
                                   result.root_x1, result.root_x2);
                        }
                        
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
                if (exit_main(log, response) == 1)
                {
                    break;
                }
            }
            else
                break;
        }
        else
            break;
    }

    printf("\n");
    return 0;
}

int solve_equation_yes_no(FILE *log, char *response)
{
    printf("Do you want to solve a quadratic eqauation Ax^2 + Bx + B = 0 ? (Y/N):");
    if (scanf("%1s", response) != EOF)
    {
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: response[0] -> %c\n", __FILE__,  __func__ ,  __LINE__, response[0]);
        if (strncmp(response, "Y", 1) == 0)
        {
            fprintf(log, "FILE: %s FUNC: %s LINE: %d: Response is Y\n", __FILE__,  __func__ ,  __LINE__);
            return 1;
        }
        else if (strncmp(response, "N", 1) == 0)
        {
            fprintf(log, "FILE: %s FUNC: %s LINE: %d: Response is N\n", __FILE__,  __func__ ,  __LINE__);
            printf("EXITING\n");
            return 0;
        }
        else
        {
            fprintf(log, "FILE: %s FUNC: %s LINE: %d: Input error: response must be a single character: Y or N\n", __FILE__,  __func__ ,  __LINE__);
            printf("Input error: response must be a single character: Y or N\n");
            printf("EXITING\nRun again the program"); // TO DO HANDLE THIS PART
            return -1;
        }
    }
    return 0;
}

int read_abc(FILE *log, char *a_array, char *b_array, char *c_array, char *response)
{
    printf("Enter A B C:");
    if (scanf("%127s %127s %127s", a_array, b_array, c_array) == 3)
    {
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: A -> %s\n",__FILE__,  __func__ ,  __LINE__, a_array);
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: B -> %s\n",__FILE__,  __func__ ,  __LINE__, b_array);
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: C -> %s\n",__FILE__,  __func__ ,  __LINE__, c_array);
        return 1;
    }
    else
    {
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: Input error: You input is more than 3 variables\n",__FILE__,  __func__ ,  __LINE__);
        printf("Input error: You input is more than 3 variables\n");
    }
    return 0;
}

int exit_main(FILE *log, char *response)
{
    printf("You want to exit ? (Y/N):");
    if (scanf("%1s", response) != EOF)
    {
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: response[0] -> %c\n", __FILE__,  __func__ ,  __LINE__, response[0]);
        if (strncmp(response, "Y", 1) == 0)
        {
            printf("EXITING\n");
            return 1;
        }
    }

    return 0;
}
