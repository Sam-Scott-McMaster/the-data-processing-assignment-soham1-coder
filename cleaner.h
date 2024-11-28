#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


float **clean_delete(float **data, int rows, int cols, int *new_rows);
float **clean_impute(float **data, int rows, int cols);