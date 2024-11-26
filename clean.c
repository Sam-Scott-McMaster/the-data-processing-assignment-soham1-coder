/*Soham Hajariwala, hajariws 11/27/2024

This program cleans up data which wil be used for machine learning

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float **read_data(int *rows,int *cols);

int main(int argc, char *argv[]) 
{
    int rows, cols;

    float **data = read_data(&rows, &cols);

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%.2f ", data[i][j]);
        }
        printf("\n");
    }
    
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