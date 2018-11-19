
#include "main.h"
#include <float.h>

// int main(int argc, char const *argv[])
// {
//     float a, b, c;
//     while(scanf("%f %f %f", &a, &b, &c) == 3){
//         printf(":: %f %f %f\n", a, b, c);
//     }
//     return 0;
// }

typedef struct _number_parts{
    size_t integer_part_len;
    size_t decimals_part_len;
    float number;
} nummber_parts;

typedef struct _roots_equation {
    nummber_parts a;
    nummber_parts b;
    nummber_parts c;
    double x1;
    double x2;
} roots_equation;

void new_line(){
    printf("\n");
}

void get_precision_details(char *array, size_t *integer_part_len, size_t *decimals_part_len){
    unsigned int len = strlen(array);
    if (len == 0){
        return;
    }
    size_t i=0;
    size_t integer_count = 0;
    size_t decimals_count = 0;
    for (i=0; i<len; i++){
        printf("%c, ", array[i]);
        integer_count++;
        if (array[i] == '.'){
            break;
        }
    }
    for (i=integer_count; i<len; i++){
        printf("%c, ", array[i]);
        decimals_count++;
    }
    integer_count--;
    *integer_part_len = integer_count;
    *decimals_part_len = decimals_count;
    new_line();
    printf("pre: %zu, %zu", integer_count, decimals_count);
    new_line();
    printf("post: %zu, %zu", *integer_part_len,  *decimals_part_len);
    new_line();
}

int validation_floats(char *array_a, char *array_b, char *array_c){

    return 1;
}

int main(int argc, char const *argv[])
{
    char a_array[1024];
    char b_array[1024];
    char c_array[1024];

    roots_equation result;
    nummber_parts num[3];
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

    while(scanf("%s %s %s", a_array, b_array, c_array) == 3){
        printf("==> %s %s %s\n", a_array, b_array ,c_array);
        get_precision_details(a_array, &a.integer_part_len, &a.decimals_part_len);
        result.a.integer_part_len = a.integer_part_len;
        result.a.decimals_part_len = a.decimals_part_len;
        
    }
    printf("::: %zu, %zu", result.a.integer_part_len , result.a.decimals_part_len);
    new_line();
   
    printf("FLT_MIN      = %+f\n", FLT_MIN);
    printf("FLT_MIN     = %e\n", FLT_MIN);
    printf("FLT_MIN     = %e\n", atof("-1.175494e-38"));
    printf("FLT_MAX      = %e\n", FLT_MAX);

    new_line();
    return 0;
}


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

//     #23.807 46.456 18.097

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
//                 x2 = get_root_add(a, b, c, d);
//                 printf("\nTwo real double roots found:");
//                 printf("\n\tRoots at: %lf & %lf\n\n", x1, x2);
//             }
//         }
//     }

//     return 0;
// }
