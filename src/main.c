
#include "main.h"

// begin

int main(int argc, char const *argv[])
{
    char a_array[1024];
    char b_array[1024];
    char c_array[1024];
    FILE *fp = fopen("logs.txt","w");

    roots_numbers result;
   
    nummber_parts a;
    a.integer_part_len = 0;
    a.decimals_part_len = 0;
    result.a = a;
    
    nummber_parts b;
    b.integer_part_len = 0;
    b.decimals_part_len = 0;
    result.b = b;

    nummber_parts c;
    c.integer_part_len = 0;
    c.decimals_part_len = 0;
    result.c = c;
    double d;
    int numRoots;
    while(scanf("%s %s %s", a_array, b_array, c_array) == 3){
        printf("==> %s %s %s\n", a_array, b_array ,c_array);
        fprintf(fp ,"==> %s %s %s\n", a_array, b_array ,c_array);
        if (validation_floats(a_array, b_array, c_array, &a, &b, &c, fp) == 1)
        {
            get_precision(a_array, b_array, c_array, &a, &b, &c, fp);
            add_numbers_to_result(&result, &a, &b, &c, fp, a_array, b_array, c_array);
            if (check_is_quadratic(result.a.f_number, fp) == 1){
                d = discrim(result.a.f_number, result.b.f_number, result.c.f_number);
                numRoots = check_discrim(d);
                if (numRoots == 0)
                {
                    printf("\tNO REAL ROOTS\n");
                }
                else if (numRoots == 1)
                {
                    double dblRoot;
                    dblRoot = get_root_minus(result.a.f_number, result.b.f_number, result.c.f_number, d);
                    printf("One real double root found:");
                    printf("\n\tRoot at: %lf\n\n", dblRoot);
                }
                else
                {
                    result.root_x1 = get_root_minus(result.a.f_number, result.b.f_number, result.c.f_number, d);
                    result.root_x2 = get_root_plus(result.a.f_number, result.b.f_number, result.c.f_number, d);
                    printf("Two real double roots found:");
                    printf("\n\tRoots at: %lf & %lf\n\n", result.root_x1, result.root_x1);
                }
            }
            
        }else{
             printf("\tINVALID\n\n");
        }
    }
    fclose (fp);
    // float t = 1/0;
    // float test1 = strtof("887.77127", NULL);
    // double test2 = strtod("887.77127", NULL);
    // printf("*** float: %f, (%f + 0.00003) = %f double: %f\n", test1, test1, test1 + 0.00003, test2);

    // printf("**** %f", FLT_MAX*2);
    // printf("FLT_MIN      = %+f\n", FLT_MIN);
    // printf("FLT_MIN     = %e\n", FLT_MIN);
    // printf("FLT_MIN     = %e\n", strtof("-1.175494e-38",NULL));
    // printf("FLT_MAX      = %e\n", FLT_MAX);

    new_line();
    return 0;
}


// end

// int main(int argc, char const *argv[])
// {
//     char a[1024];
//     char b[1024];
//     char c[1024];
//     while(scanf("%s %s %s", a, b, c) == 3){
//         printf("==> %s %s %s\n", a, b ,c);
//         double aa = strtof(a, NULL);
//         double bb = strtof(b, NULL);
//         double cc = strtof(c, NULL);
//         printf("%zu %zu %zu\n", strlen(a), strlen(b), strlen(c));
//         printf("%f %f %f\n", aa, bb, cc);
//         float aaa = strtof(a, NULL);
//         float bbb = strtof(b, NULL);
//         float ccc = strtof(c, NULL);
//         printf("%f %f %f\n", aaa, bbb, ccc);

//         printf("....\n");
//     }
//     float a1 = 23.807;
//     float b1 = 46.406;
//     float c1 = 18.8007;
//     printf("%.3f %.3f %.4f\n", a1, b1, c1);
//     printf("%lf %lf %lf\n", a1, b1, c1);
//     printf("\nEXIT\n");
//     return 0;
// }






// int main(int argc, char const *argv[])
// {
//     char a[10];
//     char b[10];
//     char c[10];
//     while(scanf("%s %s %s", a, b, c) == 3){
//         printf("==> %s %s %s\n", a, b ,c);
//         double aa = atof(a);
//         double bb = atof(b);
//         double cc = atof(c);
//         printf("%f %f %f\n", aa, bb, cc);
//         float aaa = atof(a);
//         float bbb = atof(b);
//         float ccc = atof(c);
//         printf("%f %f %f\n", aaa, bbb, ccc);

//         printf("....\n");
//     }
//     printf("\nEXIT\n");
//     return 0;
// }


// int main(int argc, char const *argv[])
// {
//     float a, b, c;
//     double d;
//     double x1, x2;

//     // #23.807 46.456 18.097

//     if (validation_input(argc, argv, &a, &b, &c) == 0)
//     {
//         if (check_nan_inf_numbers(argc, argv) == 0)
//         {
//             printf("\n");
//             printf("Value 'a' = %f\n", a);
//             printf("Value 'b' = %f\n", b);
//             printf("Value 'c' = %f\n", c);

//             d = discrim(a, b, c);

//             int numRoots;
//             numRoots = check_discrim(d);

//             if (numRoots == 0)
//             {
//                 printf("\nReturning exit code -2: NO REAL ROOTS\n\n");
//                 return (-2);
//             }
//             else if (numRoots == 1)
//             {
//                 double dblRoot;
//                 dblRoot = get_root_minus(a, b, c, d);
//                 printf("\nOne real double root found:");
//                 printf("\n\tRoot at: %lf\n\n", dblRoot);
//             }
//             else
//             {
//                 x1 = get_root_minus(a, b, c, d);
//                 x2 = get_root_plus(a, b, c, d);
//                 printf("\nTwo real double roots found:");
//                 printf("\n\tRoots at: %lf & %lf\n\n", x1, x2);
//             }
//         }
//     }

//     return 0;
// }
