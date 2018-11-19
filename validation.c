
#include "header.h"

int validation_input(int argc, char const *argv[], float *a, float *b, float *c)
{
    if (argc != 4)
    {
        printf("\nReturning error code 1: \n\tArguments must be passed for input\n\n");
        return 1;
    }

     // pointer for characters in argv[x]
    char *ptr;

    // get a
    *a = (float)strtod(argv[1], &ptr);

    // catch any characters in argument
    if (ptr[0] != 0)
    {
        // if character array is NOT empty - return error
        printf("\nReturning error code 2: \n\tInvalid argument passed for 'a' - was found to be +- Inf or NaN.\n\n");
        return 2;
    }

    // get b
    *b = (float)strtod(argv[2], &ptr);

    // catch any characters in argument
    if (ptr[0] != 0)
    {
        // if character array is NOT empty - return error
        printf("\nReturning error code 3: \n\tInvalid argument passed for 'b' - was found to be +- Inf or NaN.\n\n");
        return 3;
    }

    // get c
    *c = (float)strtod(argv[3], &ptr);

    // catch any characters in argument
    if (ptr[0] != 0)
    {
        // if character array is NOT empty - return error
        printf("\nReturning error code 4: \n\tInvalid argument passed for 'c' - was found to be +- Inf or NaN.\n\n");
        return 4;
    }  

    return 0;
}

int check_nan_inf_numbers(int argc, char const *argv[])
{
     int idx;
    // char array for error messages
    const char letters[3] = {'a','b','c'};

    // loop through all arguments
    for (idx = 1; idx < argc; idx++)
    {
        // if a, b, or c == 0
        if (atof(argv[idx]) == (double)0)
        {
            /*
            Since atof will return 0.0 given a NaN or +- Inf,
            we must check if the user meant to enter 0
            */
    
            // get length of argument's char array
            int len = strlen(argv[idx]);

            // iterator
            int i;

            // if length of argument's char array is greater than 1
            if (len > 1)
            {
                // loop through each character in the argument
                for(i = 0; i < len; i++)
                {
                    // locate the decimal point
                    if (argv[idx][i] == '.')
                    {
                        // increment i to check everything after the decimal
                        i++;

                        /*
                        if a character after the decimal point is not 0,
                        invalid number has been entered because 0.000... is 
                        valid input (except a)
                        */
                        if (argv[idx][i] != '0') 
                        {
                            printf("\nReturning error code %d: \n\tInvalid argument passed for '%c' - was found to be +- Inf or NaN.\n\n", idx + 1, letters[idx-1]);
                            return idx;
                        } 
                    }
                } 
            }
        }
    }
    return 0;
}


int check_is_quadratic(float a){
    //if a is 0 - equation is not quadratic. Print error
    if (a == (double)0)
    {
        printf("\nReturning error code -1: \n\tEquation is not quadratic - 'a' cannot be 0.\n\n");
        return(-1);
    }
    return 0;
}