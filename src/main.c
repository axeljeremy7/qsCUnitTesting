#include "main.h"

void init_var(nummber_parts *v);
int memory_ok(Line *linein, FILE *fp);
int main(int argc, char const *argv[])
{
    FILE *fp;
    printf("PASS LINE 7\n");
    fp = fopen("logs/user_logs.txt", "w");
    char a_array[512], b_array[512], c_array[512];
    roots_numbers result;
    double d;
    int numRoots;
    nummber_parts a, b, c;
    Line linein;
    linein.max = NLINE;
    char response[3]; // User response: "Y" or "N"
    if (memory_ok(&linein, fp) == 1)
    {
        printf("PASS LINE 17\n");
       
        free(linein.str);
    }
    else
    {
        return -1;
    }

    while (scanf("%s %s %s", a_array, b_array, c_array) == 3)
    {
        init_var(&a);
        result.a = a;

        init_var(&b);
        result.b = b;

        init_var(&c);
        result.c = c;

        printf("==> %s %s %s\n", a_array, b_array, c_array);
        fprintf(fp, "\nMAIN ==> %s %s %s\n", a_array, b_array, c_array);
        if (validation_floats(a_array, b_array, c_array, &a, &b, &c, fp) == 1)
        {
            get_precision(a_array, b_array, c_array, &a, &b, &c, fp);
            add_numbers_to_result(&result, &a, &b, &c, fp,
                                  a_array, b_array, c_array);

            /*printf("\n\ta == %f", result.a.f_number);
            printf(" | b == %f", result.b.f_number);
            printf(" | c == %f\n\n", result.c.f_number);*/

            if (check_is_quadratic(result.a.f_number, fp) == 1)
            {
                d = discrim(result.a.f_number,
                            result.b.f_number,
                            result.c.f_number);
                numRoots = check_discrim(d);
                if (numRoots == 0)
                {
                    printf("\tNO REAL ROOTS\n\n");
                }
                else if (numRoots == 1)
                {
                    double dblRoot;
                    dblRoot = get_root_minus(result.a.f_number,
                                             result.b.f_number,
                                             result.c.f_number, d);
                    printf("One real double root found:");
                    printf("\n\tRoot at: %lf\n\n", dblRoot);
                }
                else
                {
                    result.root_x1 = get_root_minus(result.a.f_number,
                                                    result.b.f_number,
                                                    result.c.f_number, d);
                    result.root_x2 = get_root_plus(result.a.f_number,
                                                   result.b.f_number,
                                                   result.c.f_number, d);
                    printf("Two real double roots found:");
                    printf("\n\tRoots at: %lf & %lf\n\n",
                           result.root_x1, result.root_x2);
                }
            }
            else
            {
                printf("\tNOT QUADRATIC\n\n");
            }
        }
        else
        {
            printf("\tINVALID\n\n");
        }
    }
    fclose(fp);
    // printf("\n:::::: %s %f\n"," 3.4e4" ,strtof("3.4e4",NULL));
    new_line();

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

int memory_ok(Line *linein, FILE *fp)
{
    if ((linein->str = malloc(NLINE)) == NULL)
    {
        fprintf(fp, "Systems failure no memory for malloc(%d)\n", NLINE);
        return 0;
    }
    linein->len = 0;
    linein->code = -1;
    linein->str = '\0';
    fprintf(fp, "Systems is ok for memory of malloc(%d)\n", NLINE);
    return 1;
}

int solve_equation_yes_no(char *response, FILE *fp)
{
    printf("Do you want to solve a quadratic eqauation Ax^2 + Bx + B = 0 ? (Y/N):");
    if (fgets(response, 2, stdin) == NULL)
    {
        fprintf(fp, "Input error: can not read from stdin\n");
        return -1;
    }
    if (strncmp(response, "Y", 3))
    {
        return 1;
    }
    else if (strncmp(response, "N", 3))
    {
        return 0;
    }
    else
    {
        fprintf(fp, "Input error: response must be a single character: Y or N\n");
        return -1;
    }
}