
#include "validation.h"


void new_line(){
    printf("\n");
}

void get_precision_details(char *array, int *integer_part_len, int *decimals_part_len, FILE *fp){
    size_t len = strlen(array);
    if (len == 0){
         fprintf(fp ,"Log Line 35: strlen(array) => %zu\n", len);
        return;
    }
    size_t i=0;
    int integer_count = 0;
    int decimals_count = 0;
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
    fprintf(fp ,"Log Line 57: integer_part_len => %d, %d\n", integer_count, *integer_part_len);
    fprintf(fp ,"Log Line 58:  decimals_part_len => %d, %d\n", decimals_count,  *decimals_part_len);
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
    int p_a = result->a.decimals_part_len;
    int p_b = result->b.decimals_part_len;
    int p_c = result->c.decimals_part_len;
    fprintf(fp, "Log Line 119: For a => String: %s float: %0.*f double: %0.*lf diff: %0.*lf p: %d\n", a_array, p_a, result->a.f_number, p_a, result->a.d_number, p_a,result->a.diff, p_a);
    fprintf(fp, "Log Line 120: For b => String: %s float: %0*f double: %0.*lf diff: %0.*lf p: %d\n", b_array, p_b, result->b.f_number, p_b, result->b.d_number, p_b,result->b.diff, p_b);
    fprintf(fp, "Log Line 121: For c => String: %s float: %0.*f double: %0.*lf diff: %0.*lf p: %d\n", c_array, p_c, result->c.f_number, p_c, result->c.d_number, p_c, result->c.diff, p_b);
    
}


int check_is_quadratic(float a, FILE *fp){
    //if a is 0 - equation is not quadratic. Print error
    if (a == (float)0.0)
    {
        fprintf(fp, "Equation is not quadratic - 'a' cannot be 0.\n");
        return 0;
    }
    return 1;
}

// int validation_input(int argc, char const *argv[], float *a, float *b, float *c)
// {
//     if (argc != 4)
//     {
//         printf("\nReturning error code 1: \n\tArguments must be passed for input\n\n");
//         return 1;
//     }

//      // pointer for characters in argv[x]
//     char *ptr;

//     // get a
//     *a = (float)strtod(argv[1], &ptr);

//     // catch any characters in argument
//     if (ptr[0] != 0)
//     {
//         // if character array is NOT empty - return error
//         printf("\nReturning error code 2: \n\tInvalid argument passed for 'a' - was found to be +- Inf or NaN.\n\n");
//         return 2;
//     }

//     // get b
//     *b = (float)strtod(argv[2], &ptr);

//     // catch any characters in argument
//     if (ptr[0] != 0)
//     {
//         // if character array is NOT empty - return error
//         printf("\nReturning error code 3: \n\tInvalid argument passed for 'b' - was found to be +- Inf or NaN.\n\n");
//         return 3;
//     }

//     // get c
//     *c = (float)strtod(argv[3], &ptr);

//     // catch any characters in argument
//     if (ptr[0] != 0)
//     {
//         // if character array is NOT empty - return error
//         printf("\nReturning error code 4: \n\tInvalid argument passed for 'c' - was found to be +- Inf or NaN.\n\n");
//         return 4;
//     }  

//     return 0;
// }

// int check_nan_inf_numbers(int argc, char const *argv[])
// {
//      int idx;
//     // char array for error messages
//     const char letters[3] = {'a','b','c'};

//     // loop through all arguments
//     for (idx = 1; idx < argc; idx++)
//     {
//         // if a, b, or c == 0
//         if (atof(argv[idx]) == (double)0)
//         {
//             /*
//             Since atof will return 0.0 given a NaN or +- Inf,
//             we must check if the user meant to enter 0
//             */
    
//             // get length of argument's char array
//             int len = strlen(argv[idx]);

//             // iterator
//             int i;

//             // if length of argument's char array is greater than 1
//             if (len > 1)
//             {
//                 // loop through each character in the argument
//                 for(i = 0; i < len; i++)
//                 {
//                     // locate the decimal point
//                     if (argv[idx][i] == '.')
//                     {
//                         // increment i to check everything after the decimal
//                         i++;

//                         /*
//                         if a character after the decimal point is not 0,
//                         invalid number has been entered because 0.000... is 
//                         valid input (except a)
//                         */
//                         if (argv[idx][i] != '0') 
//                         {
//                             printf("\nReturning error code %d: \n\tInvalid argument passed for '%c' - was found to be +- Inf or NaN.\n\n", idx + 1, letters[idx-1]);
//                             return idx;
//                         } 
//                     }
//                 } 
//             }
//         }
//     }
//     return 0;
// }