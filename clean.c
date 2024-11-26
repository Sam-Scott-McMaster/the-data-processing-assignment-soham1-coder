/*Soham Hajariwala, hajariws 11/27/2024

This program cleans up data which wil be used for machine learning

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

    float num;

    while (scanf("%f", &num) != EOF) 
    {
        printf("%f\n", num);
    }
    return 0;
}

//reads float values from std input and assigns them to a 2D array
float **read_data(int *rows, int *cols)
{
    scanf("%d %d", rows, cols); //obtains #of rows and columns from user

    //allocates memory for the 2D array
    float **data = (float**) malloc(*rows * sizeof(float*));

    for(int i = 0; i < *rows; i++)
    {
        data[i] = (float*) malloc(*cols * sizeof(float));

        for (int j = 0; j < *cols; j++)
        {
            float temp; //temporary variable to store the input

            if (scanf("%f", &temp) != 1) 
            {
                data[i][j] = NAN;
            } 
            
            //assigns valid numbers to the array
            else 
            {
                data[i][j] = temp; 
            }    
        }    
    }

    return data;
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