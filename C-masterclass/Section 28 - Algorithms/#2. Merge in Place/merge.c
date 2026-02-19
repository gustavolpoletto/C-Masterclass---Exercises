#include <stdlib.h>
#include <stdio.h>

#define SIZE 7

void mergeInPlace (int* a, int size);

int main()
{
    int arrA[SIZE] = {1, 4, 7, 9, 2, 5, 6};

    mergeInPlace(arrA, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", arrA[i]);
    }
    printf("\n");

    return 0;
}

void mergeInPlace (int* a, int size)
{
    int i = 0, j= 0, k= 0, p = 1;

    int* arr = malloc(sizeof(int) * size);

    while (a[i] <= a[p])
    {
        i++;
        p++;
    }
    j = p;
    i = 0;

    while(i < p  && j< size)
    {
        if(a[i] < a[j])
            arr[k++] = a[i++];
        else
            arr[k++] = a[j++];
    }

    while ( i < p)
        arr[k++] = a[i++];
    while ( j < size)
        arr[k++] = a[j++];

    for (int c = 0; c < size; c++)
    {
        a[c] = arr[c];
    }
}
