#ifndef VAR
#define VAR

typedef struct _number_parts
{
    int integer_part_len;
    int decimals_part_len;
    float f_number;
    double d_number;
    double diff;
} nummber_parts;

typedef struct _roots_numbers
{
    nummber_parts a;
    nummber_parts b;
    nummber_parts c;
    double root_x1;
    double root_x2;
} roots_numbers;

typedef struct
{
    int max;   // size of str array
    int len;   // legnth of string in str
    int code;  // status code
    char *str; // pointer to array of max bytes
} Line;

#define NLINE 100

#endif