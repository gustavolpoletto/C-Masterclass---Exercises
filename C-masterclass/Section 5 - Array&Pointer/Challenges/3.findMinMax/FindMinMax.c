#include <stdio.h>

#define SIZE 4

void findminmax (int *ptr , int size , int *minimum , int *maximum);

int main()
{
    int grades[SIZE] = { 20 , 40 , 60 , 80 };
    int min, max;

    findminmax(grades , SIZE , &min , &max);

    printf("min -> %i , max -> %i\n", min , max);

    return 0;
}

void findminmax (int *ptr , int size , int *minimum , int *maximum)
{
    *minimum = ptr[0];
    *maximum = ptr[0];
    for( int i = 1; i < size ; i++ )
    {
        if (ptr[i] < *minimum)
        {
            *minimum = ptr[i];
        }

        if (ptr[i] > *maximum)
        {
            *maximum = ptr[i];
        }
    }
}
