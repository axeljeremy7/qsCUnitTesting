#include "../include/validation.h"
#include "../include/header.h"
#include <float.h> 
#include <math.h>

double get_machine_epsilon();
int main(int argc, char const *argv[])
{
    FILE *log;
    log = stderr; //fopen("../logs/test1_logs.txt", "w");
    char *a_array, *b_array, *c_array;
    nummber_parts a, b, c;
    // roots_numbers result;
    double machine_epsilon = 10.0*get_machine_epsilon();

    printf("\nThis unit test has r1 == 1\n");
    a_array = "-34.400067";
    b_array = "46.6565677";
    c_array = "56.111011";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    int r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1); // 1
    show_precision_details(&a, &b, &c,machine_epsilon,log);
   
    printf("\nThis unit test has r1 == 1\n");
    a_array = "13.78e12";
    b_array = "9.9e12";
    c_array = "14.0e12";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1); // 1
    show_precision_details(&a, &b, &c,machine_epsilon,log);

    printf("\nThis unit test has r1 != 1\n");
    a_array = "inf";
    b_array = "-inf";
    c_array = "+inf";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1); // not 1

    printf("\nThis unit test has r1 != 1\n");
    a_array = "+80";
    b_array = "66o";
    c_array = "7o";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1); // not 1

    printf("\nThis unit test has r1 == 1\n");
    a_array = "1e";
    b_array = "1e4";
    c_array = "1e4";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1); 
    show_precision_details(&a, &b, &c,machine_epsilon,log);

    printf("\nThis unit test has r1 == 1\n");
    a_array = "1e0";
    b_array = "1e4";
    c_array = "1e4";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1); 
    show_precision_details(&a, &b, &c,machine_epsilon,log);

    printf("\nThis unit test has r1 != 1\n");
    a_array = "1e0.e3";
    b_array = "1e4.e4";
    c_array = "1e4.e6";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1);

    printf("\nThis unit test has r1 != 1\n");
    a_array = "+1e0.e-3";
    b_array = "-1e4.e+4";
    c_array = "+1e4.e-6";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1);

    printf("\nThis unit test has r1 == 1\n");
    a_array = "1.e-4";
    b_array = "1.e+4";
    c_array = "+1.e-4";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1); 
    show_precision_details(&a, &b, &c,machine_epsilon,log);

    printf("\nThis unit test has r1 == 1\n");
    a_array = "-1.e-4";
    b_array = "-1.e+4";
    c_array = "+1.e+4";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1); 
    show_precision_details(&a, &b, &c,machine_epsilon,log);

    printf("\nThis unit test has r1 != 1\n");
    a_array = "3.402823e+38";
    b_array = "3.402824e+38";
    c_array = "3.402823e+38";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1);

    printf("\nThis unit test has r1 != 1\n");
    a_array = "3.402829e+38";
    b_array = "3.402894e+38";
    c_array = "3.402923e+38";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1);

    printf("\nThis unit test has r1 != 1\n");
    a_array = "1.175494e-38";
    b_array = "1.175494e-38";
    c_array = "1.175494e-38";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1);

    printf("\nThis unit test has r1 != 1\n");
    a_array = "0.175494e-38";
    b_array = "0.175494e-38";
    c_array = "0.175494e-38";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1);

    printf("\nThis unit test has r1 == 1\n");
    a_array = "1.192093e-07";
    b_array = "2.192093e-07";
    c_array = "3.192093e-07";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1);
    show_precision_details(&a, &b, &c,machine_epsilon,log);

    // printf("\n 1.e-4 %f\n", strtof("1.e-4", NULL));
    // printf("\n 1.e+4 %f\n", strtof("1.e+4", NULL));
    // printf("\n +1.e-4 %f\n", strtof("+1.e-4", NULL));
    // printf("\n -1.e-4 %f\n", strtof("-1.e-4", NULL));
    // printf("\n -1.e+4 %f\n", strtof("-1.e+4", NULL));
    // printf("\n -1e9.e+4 %f\n", strtof("-1e3.e+4", NULL));
    // printf("\n %f\n", strtof("3.402823e+39", NULL));
    // printf("\n  %f\n", strtof("1.175494e-39", NULL));
    // printf("FLT_RADIX    = %d\n", FLT_RADIX);
    // printf("DECIMAL_DIG  = %d\n", DECIMAL_DIG);
    // printf("FLT_MIN      = %e\n", FLT_MIN);
    // printf("FLT_MAX      = %e\n", FLT_MAX);
    // printf("FLT_EPSILON  = %e\n", FLT_EPSILON);
    // printf("FLT_DIG      = %d\n", FLT_DIG);
    // printf("FLT_MANT_DIG = %d\n", FLT_MANT_DIG);
    // printf("FLT_MIN_EXP  = %d\n",  FLT_MIN_EXP);
    // printf("FLT_MIN_10_EXP  = %d\n",  FLT_MIN_10_EXP);
    // printf("FLT_MAX_EXP     = %d\n",  FLT_MAX_EXP);
    // printf("FLT_MAX_10_EXP  = %d\n",  FLT_MAX_10_EXP);
    // printf("FLT_ROUNDS      = %d\n",  FLT_ROUNDS);
    // printf("FLT_EVAL_METHOD = %d\n",  FLT_EVAL_METHOD);
    
   


    return 0;
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
