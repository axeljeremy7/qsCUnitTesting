#include "include/main.h"

void init_var(nummber_parts *v);
void init_variables(nummber_parts *a, nummber_parts *b, nummber_parts *c, roots_numbers *result);

int solve_equation_yes_no(FILE *log, char *response);

int read_abc(FILE *log, char *a_array, char *b_array, char *c_array, char *response);
int exit_main(FILE *log, char *response);

int main(int argc, char const *argv[])
{
    FILE *log;
    printf("PASS LINE 7\n");
    log = stderr; //fopen("logs/user_logs.txt", "w");
    
    char a_array[128], b_array[128], c_array[128];
    char response[2];

    roots_numbers result;
    nummber_parts a, b, c;

    while (1)
    {
        if (solve_equation_yes_no(log, response) == 1)
        {
            if (read_abc(log, a_array, b_array, c_array, response) == 1)
            {
                init_variables(&a, &b, &c, &result);
                if (exit_main(log, response) == 1){
                    printf("EXITING\n");
                    break;
                }
                    
            }
            else
            {
                printf("YOUR INPUT IS LESS THAN 3 OR GREATER THAN 3 VARIABLES");
                break;
            }
                
        }
        else
        {
            printf("EXITING\n");
            break;
        }
            
    }

    printf("\n");
    return 0;
}

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

int solve_equation_yes_no(FILE *log, char *response)
{
    printf("Do you want to solve a quadratic eqauation Ax^2 + Bx + B = 0 ? (Y/N):");
    if (scanf("%1s", response) != EOF)
    {
        fprintf(log, "obtained response -> %s\n", response);
        fprintf(log, "response[0] -> %c\n", response[0]);
        fprintf(log, "response[1] -> %c\n", response[1]);
        if (strncmp(response, "Y", 1) == 0)
        {
            fprintf(log, " Response is Y\n");
            return 1;
        }
        else if (strncmp(response, "N", 1) == 0)
        {
            fprintf(log, "Response is N\n");
            return 0;
        }
        else
        {
            fprintf(log, "Input error: response must be a single character: Y or N\n");
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
        fprintf(log, "A -> %s\n", a_array);
        fprintf(log, "B -> %s\n", b_array);
        fprintf(log, "C -> %s\n", c_array);
        return 1;
    }
    else
    {
        fprintf(log, "Input error: You input is more than 3 variables\n");
    }
    return 0;
}

int exit_main(FILE *log, char *response)
{
    printf("You want to exit ? (Y/N):");
    if (scanf("%1s", response) != EOF)
    {
        fprintf(log, "obtained response -> %s\n", response);
        fprintf(log, "response[0] -> %c\n", response[0]);
        fprintf(log, "response[1] -> %c\n", response[1]);
        if (strncmp(response, "Y", 1) == 0)
        {
            return 1;
        }
    }
    return 0;
}
