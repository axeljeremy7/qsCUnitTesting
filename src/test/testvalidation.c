#include "../include/validation.h"
#include "../include/header.h"


int main(int argc, char const *argv[])
{
    FILE *log;
    log = stderr; //fopen("../logs/test1_logs.txt", "w");
    char *a_array, *b_array, *c_array;
    nummber_parts a, b, c;
    // roots_numbers result;
    a_array = "-34.400067";
    b_array = "46.6565677";
    c_array = "56.111011";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);

    int r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1);


    a_array = "1.0e12 ";
    b_array = "9.9e12";
    c_array = "14.0e12";
    printf("A -> %s\n", a_array);
    printf("B -> %s\n", b_array);
    printf("C -> %s\n", c_array);
    r1 = validation_floats(a_array, b_array, c_array, &a, &b, &c, log);
    printf("r1 -> %d\n\n", r1);

    printf("ALL OK\n\n");
    return 0;
}
