/*Soham Hajariwala, hajariws 11/28/2024

This program cleans up data stored in 2D arrays which wil be used for machine learning

2 cleaning options:

deletion strategy which deletes rows with NAN values (must use "-d" flag)

imputation strategy which replaces NAN values with the average of its column (no flag needed)

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "cleaner.h"

//function prototypes
float **read_data(int *rows,int *cols);
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

//reads float values from std input and assigns them to a 2D array then returns it
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

//takes in a 2D array and outputs it in a nice format
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