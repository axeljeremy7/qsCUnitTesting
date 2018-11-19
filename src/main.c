
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

typedef struct _roots_numbers {
    nummber_parts a;
    nummber_parts b;
    nummber_parts c;
    double x1;
    double x2;
} roots_numbers;

void new_line(){
    printf("\n");
}

void get_precision_details(char *array, size_t *integer_part_len, size_t *decimals_part_len, FILE *fp){
    size_t len = strlen(array);
    if (len == 0){
         fprintf(fp ,"Log Line 35: strlen(array) => %zu\n", len);
        return;
    }
    size_t i=0;
    size_t integer_count = 0;
    size_t decimals_count = 0;
    for (i=0; i<len; i++)
    {
        printf("%c, ", array[i]);
        integer_count++;
        if (array[i] == '.'){
            break;
        }
    }
    for (i=integer_count; i<len; i++)
    {
        printf("%c, ", array[i]);
        decimals_count++;
    }
    integer_count--;
    *integer_part_len = integer_count;
    *decimals_part_len = decimals_count;
    fprintf(fp ,"Log Line 57: integer_part_len => %zu, %zu\n", integer_count, *integer_part_len);
    fprintf(fp ,"Log Line 58:  decimals_part_len => %zu, %zu\n", decimals_count,  *decimals_part_len);
}

void get_precision(char *a_array, char *b_array, char *c_array, nummber_parts *a, nummber_parts *b, nummber_parts *c){
    // get_precision_details(a_array, &a.integer_part_len, &a.decimals_part_len, fp);
    // get_precision_details(b_array, &b.integer_part_len, &b.decimals_part_len, fp);
    // get_precision_details(c_array, &c.integer_part_len, &c.decimals_part_len, fp);
}

int validate_float(char *array, nummber_parts *n, FILE *fp){
    float test = strtof(array, NULL);
    size_t len = strlen(array);
    size_t i;
    int return_value = 1;
    if (test == (float)0.0)
    {
        for (i = 0; i < len; i++)
        {
            if (array[i] < 48 || array[i] > 57)
            {
                return_value = 2;
                fprintf (fp, "Error Line 73: The input for a is %s, which is invalid.\n", array);
                break;
            }
        }
    }

    if (return_value == 1)
    {
        n->number = strtof(array, NULL);
        fprintf(fp, "Log Line 82: The input for a is %s == %f, which is valid.\n", array, n->number);
    }

    return return_value;
}

int validation_floats(char *array_a, char *array_b, char *array_c, nummber_parts *a, nummber_parts *b, nummber_parts *c, FILE *fp){
    int r1 = validate_float(array_a, a,  fp);
    int r2 = validate_float(array_b, b, fp);
    int r3 = validate_float(array_c, c, fp);
    if (r1 + r2 + r3 != 3)
    {
        return 2;
    }
    fprintf(fp, "Log LINE 96: %d %d %d\n", r1, r2, r3);
    return 1;
}


void add_numbers(roots_numbers *result, nummber_parts *a, nummber_parts *b, nummber_parts *c, FILE *fp){
    result->a = *a;
    result->a.integer_part_len = a->integer_part_len;
    result->a.decimals_part_len = a->decimals_part_len;
    printf("^^ %zu %zu %f\n", result->a.integer_part_len, result->a.decimals_part_len, result->a.number);
    result->b = *b;
    result->b.integer_part_len = b->integer_part_len;
    result->b.decimals_part_len = b->decimals_part_len;
    printf("^^ %zu %zu %f\n", result->b.integer_part_len, result->b.decimals_part_len, result->b.number);
    result->c = *c;
    result->c.integer_part_len = c->integer_part_len;
    result->c.decimals_part_len = c->decimals_part_len;
    printf("^^ %zu %zu %f\n", result->c.integer_part_len, result->c.decimals_part_len, result->c.number);
    
}


int main(int argc, char const *argv[])
{
    char a_array[1024];
    char b_array[1024];
    char c_array[1024];
    FILE *fp = fopen("error.txt","w");

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
   
    // int r2;
    while(scanf("%s %s %s", a_array, b_array, c_array) == 3){
        printf("==> %s %s %s\n", a_array, b_array ,c_array);
        fprintf(fp ,"==> %s %s %s\n", a_array, b_array ,c_array);
        if (validation_floats(a_array, b_array, c_array, &a, &b, &c, fp) == 1)
        {
            
            add_numbers(&result, &a, &b, &c, fp);
            new_line();
        }
        else
        {
            printf("NOT ONE \n");
        }
        
    }
    printf("::: %zu, %zu\n", result.a.integer_part_len , result.a.decimals_part_len);
    printf("::: %zu, %zu\n", result.b.integer_part_len , result.b.decimals_part_len);
    printf("::: %zu, %zu\n", result.c.integer_part_len , result.c.decimals_part_len);
    // new_line();
    
    // float t;
    // printf("FLT_MIN      = %+f\n", FLT_MIN);
    // printf("FLT_MIN     = %e\n", FLT_MIN);
    // printf("FLT_MIN     = %e\n", strtof("-1.175494e-38",NULL));
    // printf("FLT_MAX      = %e\n", FLT_MAX);

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
