#include "include/main.h"

int clean_stdin();
int solve_equation_yes_no(FILE *log, char *response);
int read_abc(FILE *log, char *a_array, char *b_array, char *c_array, char *response, char *line);
int exit_main(FILE *log, char *response);
int show_roots(float a, float b, float c, FILE *log, double *discriminant, int *num_roots, roots_numbers *result);
double get_machine_epsilon();

int main(int argc, char const *argv[])
{
    FILE *log;
    log = stderr; //fopen("logs/user_logs.txt", "w");

    char a_array[32], b_array[32], c_array[32];
    char response[2];

    roots_numbers result;
    nummber_parts a, b, c;
    double discriminant;
    int num_roots;
    double machine_epsilon = get_machine_epsilon();
    int again = 0;
    int yn = 1 ;
     char *line = malloc(100);
    while (1)
    {
        if (again == 0){
            yn = solve_equation_yes_no(log, response);
        }

        if (yn == 1 || again == 1)
        {
            if (read_abc(log, a_array, b_array, c_array, response, line) == 1)
            {
                init_variables(&a, &b, &c, &result);
                if (validation_floats(a_array, b_array, c_array, &a, &b, &c, log) == 1)
                {
                    add_abc_to_result(&result, &a, &b, &c, log);
                    show_precision_details(&(result.a), &(result.b), &(result.c), machine_epsilon, log);
                    if (check_is_quadratic(result.a.f_number, log) == 1)
                    {
                        show_roots(result.a.f_number, result.b.f_number, result.c.f_number, log, &discriminant, &num_roots, &result);
                        again = 0;
                        continue;
                    }
                    else
                    {
                        again = 1;//break;
                    }
                }
                else
                {
                    again = 1;//break;
                }
            }
            else
            {
                again = 1;
                //continue;
            }
                
        }
        else
            break;
    }
    free(line);
    fclose(log);
    printf("\n");
    return 0;
}

int solve_equation_yes_no(FILE *log, char *response)
{
    printf("Do you want to solve a quadratic equation Ax^2 + Bx + B = 0 ? (Y for yes/ Any letter for exit):");
    if (scanf("%1s", response) != EOF)
    {
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: response[0] -> %c\n", __FILE__, __func__, __LINE__, response[0]);
        if (strncmp(response, "Y", 1) == 0)
        {
            fprintf(log, "FILE: %s FUNC: %s LINE: %d: Response is Y\n", __FILE__, __func__, __LINE__);
            return 1;
        }
        // else if (strncmp(response, "N", 1) == 0)
        // {
        //     fprintf(log, "FILE: %s FUNC: %s LINE: %d: Response is N\n", __FILE__, __func__, __LINE__);
        //     printf("EXITING\n");
        //     return 0;
        // }
        else
        {
            // fprintf(log, "FILE: %s FUNC: %s LINE: %d: Input error: response must be a single character: Y or N\n", __FILE__, __func__, __LINE__);
            // printf("Input error: response must be a single character: Y or N\n");
            printf("EXITING\n");
            return -1;
        }
    }
    return 0;
}

int read_abc(FILE *log, char *a_array, char *b_array, char *c_array, char *response, char *line)
{
    printf("Enter A B C: ");
    char c ;
    // int args = -1;
    // char *line = malloc(100);
    fgets(line, 100, stdin);
    int args = sscanf(line,"%32s %32s %32s%c", a_array, b_array, c_array, &c);
    // clean_stdin();
    // fseek(stdin,SEEK_END,SEEK_END);
    // printf("\n");
    fprintf(log, "FILE: %s FUNC: %s LINE: %d: args -> %d\n", __FILE__, __func__, __LINE__, args);
    int r;
    if ( args == 4 && c == '\n' )//&& c == '\n'
    {
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: A -> %s\n", __FILE__, __func__, __LINE__, a_array);
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: B -> %s\n", __FILE__, __func__, __LINE__, b_array);
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: C -> %s\n", __FILE__, __func__, __LINE__, c_array);
        r = 1;
    }
    else
    {
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: Input error: You input is more than 3 variables\n", __FILE__, __func__, __LINE__);
        printf("Input error: You input is more or less than 3 variables\n");
        r = 0;
    }
    fprintf(log, "FILE: %s FUNC: %s LINE: %d: args -> %d  r -> %d c -> |%c|\n", __FILE__, __func__, __LINE__, args, r, c);
    // free(line);
    return r;
}

int clean_stdin()
{
    while (getchar()!='\n');
    // int i = 0;
    // while(i < 3)
    // {
    //     getchar();
    //     i++;
    // }
    return 1;
}

int exit_main(FILE *log, char *response)
{
    printf("You want to exit ? (Y/N):");
    if (scanf("%1s", response) != EOF)
    {
        fprintf(log, "FILE: %s FUNC: %s LINE: %d: response[0] -> %c\n", __FILE__, __func__, __LINE__, response[0]);
        if (strncmp(response, "Y", 1) == 0)
        {
            printf("EXITING\n");
            return 1;
        }
    }

    return 0;
}

int show_roots(float a, float b, float c, FILE *log, double *discriminant, int *num_roots, roots_numbers *result)
{
    *discriminant = discrim(a, b, c, log);
    *num_roots = check_discrim(*discriminant, log);
    if (*num_roots == 1)
    {
        result->root_x1 = get_root_minus(a, b, c, *discriminant, log);
        printf("\n\tRoots at: %lf \n\n", result->root_x1);
    }
    else if (*num_roots == 2)
    {
        result->root_x1 = get_root_minus(a, b, c, *discriminant, log);
        result->root_x2 = get_root_plus(a, b, c, *discriminant, log);
        printf("\n\tRoots at: %lf & %lf\n\n", result->root_x1, result->root_x2);
    }
    return *num_roots;
}

double get_machine_epsilon()
{
    double dm;
    double macheps = 0.5;

    while ((1.0 + (dm = macheps / 2.0)) != 1.0)
    {
        macheps = dm;
    }
    return macheps;
}

// dont remove yet
//  if (exit_main(log, response) == 1)
//                         {
//                             break;
//                         }
//                         else
//                         {
//                             continue;
//                         }