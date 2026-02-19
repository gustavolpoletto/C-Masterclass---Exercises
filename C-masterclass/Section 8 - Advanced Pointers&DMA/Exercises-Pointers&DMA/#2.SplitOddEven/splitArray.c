//From a given array, create 2 dynamicallya alocated arrays
// array {12, 5, 7, 8, 3, 10, 4, 9} -> even {12, 8, 10, 4} -> odd {5, 7, 3, 9}

#include <stdlib.h>
#include <stdio.h>

void splitArray(int* arr, int size, int** OddArr, int** EvenArr, int*oddcount, int*evencount);
void print_array(int* ptr, int size);

#define SIZE 8

int main ()
{
    int array[] = {12, 5, 7, 8, 3, 10, 4, 9};
    int* OddArray = NULL;
    int* EvenArray = NULL;
    int oddSize = 0, evenSize = 0;

    splitArray(array, SIZE, &OddArray, &EvenArray, &oddSize, &evenSize);

    print_array(OddArray, oddSize);
    print_array(EvenArray, evenSize);
}

void splitArray(int* arr, int size, int**OddArr, int**EvenArr, int*oddcount, int*evencount)
{
    int oddinsert = 0;
    int eveninsert = 0;
    for(int i = 0; i < size; i++)
    {
        (arr[i] % 2 == 0) ? (*evencount)++ : (*oddcount)++;
    }

    int* Odd_Array = (int*)malloc(*oddcount * sizeof(int));
    int* Even_Array = (int*)malloc(*evencount * sizeof(int));

    for(int j = 0; j < size; j++)
    {
        if (arr[j] % 2 == 0)
        {
            Even_Array[eveninsert] = arr[j];
            eveninsert++;
        }
        else
        {
            Odd_Array[oddinsert] = arr[j];
            oddinsert++;
        }
    }

    *OddArr = Odd_Array;
    *EvenArr = Even_Array;
}
void print_array(int* ptr, int size)
{
    for (int i = 0; i < size; i++){
        printf("%i ", ptr[i]);
    }
    printf("\n");
}
