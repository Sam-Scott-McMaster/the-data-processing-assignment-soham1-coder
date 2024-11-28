/*Soham Hajariwala, hajariws 11/27/2024

This program cleans up data which wil be used for machine learning

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//function prototypes
float **read_data(int *rows,int *cols);
float **clean_delete(float **data, int rows, int cols, int *new_rows);
float **clean_impute(float **data, int rows, int cols);
void output_data(float **data, int rows, int cols);

int main(int argc, char *argv[]) 
{
    //variable declaration
    int rows, cols;
    int new_rows;
    float **cleaned_data;

    //creates original data array  
    float **data = read_data(&rows, &cols);

    //outputs original data
    printf("\n");
    output_data(data,rows,cols);

    //uses deletion strategy if "-d" flag is used
    if (argc > 1 && strcmp(argv[1], "-d") == 0)
    {
        printf("\n");
        cleaned_data = clean_delete(data, rows, cols, &new_rows);
        output_data(cleaned_data,new_rows,cols);
    }

    //uses imputation strategy otherwise
    else
    {
        printf("\n");
        cleaned_data = clean_impute(data, rows, cols); 
        output_data(cleaned_data,rows,cols);
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

    //allocates memory for an array to store valid rows
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

//copies the array, replaces NaN values with the average of its column and returns the cleaned array
float **clean_impute(float **data, int rows, int cols)
{
    //allocates memory for a new array with cleaned data
    float **cleaned_data = (float**) malloc(rows * sizeof(float*));

    //Allocates memory for an array within the new array (2D array)
    for (int i = 0; i < rows; i++) 
    {
        cleaned_data[i] = (float *)malloc(cols * sizeof(float));
    }

    //iterates column by column
    for (int j = 0; j < cols; j++) 
    {
        float sum = 0;
        float average = 0;
        int nan_count = 0;

        for (int i = 0; i < rows; i++) 
        {
            if (isnan(data[i][j])) 
            {
                nan_count++;
            }

            else
            {
                sum += data[i][j];
            }
        }
        
        if (rows - nan_count > 0) //avoids division by zero
        {
            average = sum / (rows - nan_count);
        }

        else
        {
            average = 0; //average for column of all NAN values
        }

        //clones the array while replacing NAN values in the column with the average
        for (int i = 0; i < rows; i++) 
        {
            if (isnan(data[i][j])) 
            {
                cleaned_data[i][j] = average;
            }

            else
            {
                cleaned_data[i][j] = data[i][j];
            }
        }
    }
    return cleaned_data;
}

void output_data(float **data, int rows, int cols)
{
    for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                printf("%.2f ", data[i][j]);
            }
            printf("\n");
        }       
}