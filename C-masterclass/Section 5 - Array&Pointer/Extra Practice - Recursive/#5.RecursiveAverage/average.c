#include <stdio.h>

double average(int *ptr, int size);

#define SIZE 3

int main()
{
    int arr[SIZE] = {1, 3, 4};
    double avr = average(arr, SIZE);

    printf("avr: %f\n", avr);
}

double average(int *ptr, int size)
{
    if (size== 1)
    {
        return ptr[0];
    }
    return (ptr[0] + average(ptr + 1, size - 1) * (size - 1)) / size;
}
