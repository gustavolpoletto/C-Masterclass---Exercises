#include <stdio.h>

void swap_array(int* arr1, int *arr2, int size);
void swap(int *val1, int* val2);
void print_array (int* arr, int size);

#define SIZE 5

int main ()
{
    int array1 [SIZE] = {0, 1, 2, 3, 4};
    int array2 [SIZE] = {5, 6, 7, 8, 9};

    swap_array(array1, array2, SIZE);

    print_array(array1, SIZE);

    print_array(array2, SIZE);
}

void swap_array(int* arr1, int *arr2, int size)
{
    if (size == 0)
        return;

    swap(arr1, arr2);

    swap_array(arr1 + 1, arr2 + 1, size - 1);
}

void swap(int *val1, int* val2)
{
    int temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void print_array (int* arr, int size)
{
    for (int i = 0; i< SIZE; i++)
        printf("%i ", arr[i]);
    printf("\n");
}
