#include "include/file_main.h"

// begin

void init_var(nummber_parts * v){
    v->integer_part_len = 0;
    v->decimals_part_len = 0;
    v->f_number = 0;
    v->d_number = 0;
    v->diff = 0;
}

int main(int argc, char const *argv[])
{
    // v2
    printf("argc: %d , argv[1]: %s, atoi(argv[1])): %d \n", argc, argv[1], atoi(argv[1]));
    FILE *fp;
    if (atoi(argv[1]) == 1)
    {
        fp = fopen("logs/val1_logs.txt", "w");
    }
    else if (atoi(argv[1]) == 2)
    {
        fp = fopen("logs/val2_logs.txt", "w");
    }
    else
    {
        fp = fopen("logs/user_logs.txt", "w");
    }
    char a_array[1024];
    char b_array[1024];
    char c_array[1024];

    roots_numbers result;

    double d;
    int numRoots;
    nummber_parts a, b, c;
    // only can be used with stdin from a file, not from terminal
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