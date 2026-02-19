//create a copy array and pass by reference

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_int_array(int* ptr, int size);
void print_double_array(double* ptr, int size);
void copyArr (void* original, int size, void** copied, int elem_size);

int main()
{
    int size = 5;
    double arr[] = {1.3, 6.9, 2.2, 10.9, 7.11};
    double* copy = NULL;

    copyArr (arr, size, (void*)&copy, sizeof(double));

    printf("original Array\n");
    print_double_array(arr, size);
    printf("Copied Array\n");
    print_double_array(copy, size);

    free(copy);
}

void print_int_array(int* ptr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%i ", ptr[i]);
    }
    printf("\n");
}

void print_double_array(double* ptr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%.1f ", ptr[i]);
    }
    printf("\n");
}


void copyArr (void* original, int size, void** copied, int elem_size)
{
    void* tempArr = (void*)malloc(size * elem_size);
    memcpy(tempArr, original, size * elem_size);

    *copied = tempArr;
}
