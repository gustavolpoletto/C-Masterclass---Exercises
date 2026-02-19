// delete an item from array -  8, 9, 10 -> 8, 10

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_int_array(int* ptr, int size);
void inicArray (int* ptr, int size);
void* deleteNumber (void* ptr, int* size, int del_place, int elem_size);


int main (void)
{
    int size = 5;
    int del;
    int* array = malloc(size * sizeof(int));
    inicArray(array, size);
    print_int_array(array, size);
    printf("Delete number in position: ");
    scanf("%i", &del);
    printf("Final Array\n");
    int* new_arr = deleteNumber(array, &size, del, sizeof(int));
    print_int_array(new_arr, size);
}

void* deleteNumber (void* ptr, int* size, int del_place, int elem_size)
{
    void* arr = (char*)malloc((*size - 1) * elem_size);
    if (!arr) {
        free(ptr);
        free(arr);
        return NULL;
    }

    memcpy(arr, ptr, elem_size * del_place);
    memcpy(arr + del_place * elem_size , ptr + elem_size * (del_place + 1), elem_size * (*size - del_place - 1));

    *size = *size - 1;
    free(ptr);
    return arr;
}


void inicArray (int* ptr, int size)
{
    for (int i = 0; i < size; i++)
        ptr[i] = i;
}

void print_int_array(int* ptr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%i ", ptr[i]);
    }
    printf("\n");
}

