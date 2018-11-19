
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
    float f_number;
    double d_number;
    double diff;
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
        // printf("%c, ", array[i]);
        integer_count++;
        if (array[i] == '.'){
            break;
        }
    }
    for (i=integer_count; i<len; i++)
    {
        // printf("%c, ", array[i]);
        decimals_count++;
    }
    integer_count--;
    *integer_part_len = integer_count;
    *decimals_part_len = decimals_count;
    fprintf(fp ,"Log Line 57: integer_part_len => %zu, %zu\n", integer_count, *integer_part_len);
    fprintf(fp ,"Log Line 58:  decimals_part_len => %zu, %zu\n", decimals_count,  *decimals_part_len);
}

void get_precision(char *a_array, char *b_array, char *c_array, nummber_parts *a, nummber_parts *b, nummber_parts *c, FILE *fp){
    get_precision_details(a_array, &(a->integer_part_len), &(a->decimals_part_len), fp);
    get_precision_details(b_array, &(b->integer_part_len), &(b->decimals_part_len), fp);
    get_precision_details(c_array, &(c->integer_part_len), &(c->decimals_part_len), fp);
}

int validate_float(char *array, nummber_parts *n, FILE *fp, char id){
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
        n->f_number = strtof(array, NULL);
        n->d_number = strtod(array, NULL);
        n->diff =  n->d_number -  n->f_number;
        fprintf(fp, "Log Line 92: The input for %c is %s which is valid.\n", id, array);
    }

    return return_value;
}

int validation_floats(char *array_a, char *array_b, char *array_c, nummber_parts *a, nummber_parts *b, nummber_parts *c, FILE *fp){
    int r1 = validate_float(array_a, a,  fp, 'a');
    int r2 = validate_float(array_b, b, fp, 'b');
    int r3 = validate_float(array_c, c, fp, 'c');
    if (r1 + r2 + r3 != 3)
    {
        return 2;
    }
    fprintf(fp, "Log LINE 96: %d %d %d\n", r1, r2, r3);
    return 1;
}


void add_numbers_to_result(roots_numbers *result, nummber_parts *a, nummber_parts *b, nummber_parts *c, FILE *fp, char *a_array, char *b_array, char *c_array){
    result->a = *a;
    result->b = *b;
    result->c = *c;
     // fprintf(fp, "Log LINE 112: %s\n",  "Checking if passing has been successful"); TODO: LATER TO IMPLEMENT
    int p_a =   (int)result->a.decimals_part_len;
    int p_b =   (int)result->b.decimals_part_len;
    int p_c =   (int)result->c.decimals_part_len;
    fprintf(fp, "Log Line 119: For a => String: %s float: %0.*f double: %0.*lf diff: %0.*lf p: %d\n", a_array, p_a, result->a.f_number, p_a, result->a.d_number, p_a,result->a.diff, p_a);
    fprintf(fp, "Log Line 120: For b => String: %s float: %0*f double: %0.*lf diff: %0.*lf p: %d\n", b_array, p_b, result->b.f_number, p_b, result->b.d_number, p_b,result->b.diff, p_b);
    fprintf(fp, "Log Line 121: For c => String: %s float: %0.*f double: %0.*lf diff: %0.*lf p: %d\n", c_array, p_c, result->c.f_number, p_c, result->c.d_number, p_c, result->c.diff, p_b);
    
}



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
   
    while(scanf("%s %s %s", a_array, b_array, c_array) == 3){
        printf("==> %s %s %s\n", a_array, b_array ,c_array);
        fprintf(fp ,"==> %s %s %s\n", a_array, b_array ,c_array);
        if (validation_floats(a_array, b_array, c_array, &a, &b, &c, fp) == 1)
        {
            get_precision(a_array, b_array, c_array, &a, &b, &c, fp);
            add_numbers_to_result(&result, &a, &b, &c, fp, a_array, b_array, c_array);
            new_line();
        }
    }

    // float t = 1/0;
    float test1 = strtof("887.77127", NULL);
    double test2 = strtod("887.77127", NULL);
    printf("*** float: %f, (%f + 0.00003) = %f double: %f\n", test1, test1, test1 + 0.00003, test2);

    printf("**** %f", FLT_MAX*2);
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
