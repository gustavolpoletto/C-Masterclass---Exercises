// Create a new  dinamical allocated array with no duplicates by a given sorted array
#include <stdlib.h>
#include <stdio.h>

int* NoDuplicatedArray (int* ptr, int size, int* final_size);
void print_array(int* ptr, int size);

#define SIZE 10

int main ()
{
    int newsize;
    int array[] = {1, 3, 3, 5, 7, 7, 7, 8, 12, 12};

    int* NoDuplicate = NoDuplicatedArray(array, SIZE, &newsize);

    print_array(NoDuplicate, newsize);
}

int* NoDuplicatedArray (int* ptr, int size, int* final_size)
{
    int count = 1;
    for (int i = 0; i < size - 1; i++)
    {
        if(ptr[i] != ptr[i + 1])
            count++;
    }

    int * arr = (int*)malloc(count * sizeof(int));
    arr[0] = ptr[0];
    int insert = 1;
    for (int j = 0; j< size; j++)
    {
        if(ptr[j] != ptr[j + 1]){
            arr[insert] = ptr[j + 1];
            insert++;
        }
    }
    *final_size = count;
    return arr;
}

int size = 10
