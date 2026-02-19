// calculates the maximum sum of two adjacent numbers in a array

#include <stdio.h>

int max_adjacent_sum (int*ptr , int size, int *store_max);

#define SIZE 5

int main ()
{
    int arr[SIZE] = {4, 2, 7, 9, 5};
    int max = arr[0] + arr[1];
    max = max_adjacent_sum(arr , SIZE , &max);

    printf("max sum of adjacents -> %i\n", max);
}

int max_adjacent_sum (int*ptr , int size, int *store_max)
{
    if (size == 1)
        return *store_max;

    if (ptr[0] + ptr[1] > *store_max)
        *store_max = ptr[0] + ptr[1];

    return max_adjacent_sum(ptr + 1 , size - 1 , store_max);
}
