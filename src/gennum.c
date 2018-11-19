#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    srand(0);
    fp = fopen("test.in", "w");

    double i;
    double end = pow(10.0, 3.0);

    for(i = 0; i < end; i++)
    {
        float a = ((float)rand()/(float)(RAND_MAX)) * 5.0;
        float b = ((float)rand()/(float)(RAND_MAX)) * 5.0;
        float c = ((float)rand()/(float)(RAND_MAX)) * 5.0;

        fprintf(fp, "%f %f %f\n", a, b, c);  
    }
    fclose (fp);

    printf("::: %f\n", end);

    return 0;
}
