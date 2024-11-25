#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    float num;

    while (scanf("%f", &num) != EOF) 
    {
        printf("%f\n", num);
    }
    return 0;
}


float read_data(int rows, int cols)
{
    scanf("%d %d", rows, cols); //obtains #of rows and columns from user

}

float clean_delete(float *a[])
{

}

float clean_impute(float *a[])
{

}

void output_data(float *a[])
{

}