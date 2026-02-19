//Insert to array -> Inicial {8, 6, 2}
// function -> insert 15 in index 2
// Final {8, 6, 15, 2}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_int_array(int* ptr, int size);
void* insertArray(void* array, int* len, int elem_size, int pos, void* elem);

int main()
{
    int arrsize = 3;
    int* array = malloc(arrsize * sizeof(int));

    array[0] = 8;
    array[1] = 6;
    array[2] = 2;

    printf("Int inicial arr: ");
    print_int_array(array, arrsize);

    int value;
    printf("Insert Value: ");
    scanf("%i", &value);

    int pos;
    do {
        printf("Insert position: ");
        scanf("%i", &pos);
    } while (pos <= 0 || pos > arrsize);
    pos -= 1;

    array = insertArray(array, &arrsize, sizeof(int), pos, &value);

    printf("Int final arr: ");
    print_int_array(array, arrsize);

    free(array);
    return 0;
}

void* insertArray(void* array, int* len, int elem_size, int pos, void* elem)
{
    void* newArr = malloc((*len + 1) * elem_size);
    if (!newArr) return NULL;

    // Copy to posicion
    memcpy((char*)newArr, array, elem_size * pos);

    // Insert element
    memcpy((char*)newArr + elem_size * pos, elem, elem_size);

    // Copy missing
    memcpy((char*)newArr + elem_size * (pos + 1),
           (char*)array + elem_size * pos,
           elem_size * (*len - pos));

    *len += 1;

    free(array);
    return newArr;
}

void print_int_array(int* ptr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%i ", ptr[i]);
    }
    printf("\n");
}
