/*Soham Hajariwala, hajariws 11/27/2024

This program cleans up data which wil be used for machine learning

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float **read_data(int *rows,int *cols);
float **clean_delete(float **data, int rows, int cols, int *new_rows);

int main(int argc, char *argv[]) 
{
    int rows, cols;
    int new_rows;

    float **data = read_data(&rows, &cols);
    float **cleaned_data = clean_delete(data, rows, cols, &new_rows);

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%.2f ", data[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");

    for (int x = 0; x < new_rows; x++) 
    {
        for (int y = 0; y < cols; y++) 
        {
            printf("%.2f ", cleaned_data[x][y]);
        }
        printf("\n");
    }

    free(data);
    free(cleaned_data);
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

//copies the array, deletes rows with invalid values and returns the cleaned array
float **clean_delete(float **data, int rows, int cols, int *new_rows)
{

    //allocates memory for a temporary array to store valid rows
    float **cleaned_data = (float**) malloc(rows * sizeof(float*));

    int valid_rows = 0; //number of valid rows

    for (int i = 0; i < rows; i++) 
    {
        int has_nan = 0; //indicates if a row has a nan value

        for (int j = 0; j < cols; j++) 
        {
            if (isnan(data[i][j])) 
            {
                has_nan = 1; //nan is found
                break; 
            }
        }

        if (!has_nan)
        {
            //allocates memory for the valid row
            cleaned_data[valid_rows] = (float*) malloc(cols * sizeof(float));

            //copy the valid row to the new array
            for (int j = 0; j < cols; j++) 
            {
                cleaned_data[valid_rows][j] = data[i][j];
            }
            valid_rows++;
        }
    }

    //reallocates the memory of the cleaned_data array to fit the number of valid rows
    cleaned_data = (float**) realloc(cleaned_data, valid_rows * sizeof(float*));
    *new_rows = valid_rows;

    return cleaned_data;
}


float clean_impute(float *a[])
{

}

void output_data(float *a[])
{

}