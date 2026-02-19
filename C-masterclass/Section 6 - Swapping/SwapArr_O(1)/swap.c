#include <stdio.h>
#include <stdlib.h>

void swap_arrayO1(int** arr1, int** arr2);
void swap(int *val1, int* val2);
void print_array (int* arr, int size);
int *generateArray (int size);

int main ()
{
    int *array1 = NULL, *array2 = NULL, size1, size2;

    printf("enter size array 1:");
    scanf("%d", &size1);

    printf("enter size array 2:");
    scanf("%d", &size2);

    array1 = generateArray(size1);
    array2 = generateArray(size2);


    swap_arrayO1(&array1, &array2);
    swap(&size1, &size2);

    print_array(array1, size1);

    print_array(array2, size2);

    free(array1);
    free(array2);

    return 0;
}

void swap_arrayO1(int** arr1, int**arr2)
{
    int* temp;
    temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
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
    for (int i = 0; i< size; i++)
        printf("%i ", arr[i]);
    printf("\n");
}

int *generateArray (int size)
{
    int* arr = (int*)malloc(size * sizeof(int));

        if (arr == NULL) {
        printf("Alocation error\n");
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        printf("%i°: ", i + 1);
        scanf("%d", &arr[i]);
    }


    return arr;
}
