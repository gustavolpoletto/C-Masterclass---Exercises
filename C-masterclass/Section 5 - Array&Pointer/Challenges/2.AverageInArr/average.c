#include <stdio.h>

#define SIZE 4

int sumArray (int *ptr , int size);
double average (int *ptr, int size);

int main()
{
    int grades[SIZE] = {22 , 35, 51, 90};
    double result;

    result = average(grades , SIZE);

    printf("Average -> %f\n",result);
}

double average (int *ptr, int size)
{
    float avr = sumArray(ptr , size) / (double)size;
    return avr;
}

int sumArray (int *ptr , int size)
{
    int sum = 0;

    for( int i = 0; i < size ; i++ )
    {
        sum = sum + ptr[i];
    }
    return sum;

}
