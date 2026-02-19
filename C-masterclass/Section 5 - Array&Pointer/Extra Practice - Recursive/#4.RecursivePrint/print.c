#include <stdio.h>

void print_left(int *ptr, int size);
void print_right(int *ptr, int size);

#define SIZE 4

int main()
{
    int arr[SIZE] = {1, 2, 3, 4};

    print_left(arr, SIZE);

    print_right(arr,SIZE);
}

void print_left(int *ptr, int size)
{
    if(size == 0)
    {
        printf("\n");
        return;
    }
    printf("%i ", ptr[0]);
    print_left(ptr + 1, size - 1);
}

void print_right(int *ptr, int size)
{
    if(size == 0)
    {
        printf("\n");
        return;
    }
    printf("%i ", ptr[size - 1]);
    print_right(ptr, size - 1);
}
