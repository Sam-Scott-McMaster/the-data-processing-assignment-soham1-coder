#include <stdio.h>
#include <stdlib.h>

int main() {

    float num;

    while (scanf("%f", &num) != EOF) 
    {
        printf("%f\n", num);
    }
    return 0;
}