#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *create_arr (int* final_size);
void print_array (int* arr, int size);

int main(){
    int size;
    int* arr = create_arr(&size);
    print_array(arr, size);

}

int *create_arr (int* final_size)
{
    int size = 0;
    int input;
    int* arr = NULL;

    printf("Próximo Número (-1 para sair):");
    scanf("%i", &input);

    while(input != -1)
    {
        int* temp = realloc(arr, (size + 1) * sizeof(int));
        if (!temp) return NULL;
        arr = temp;

        arr[size] = input;
        size++;

        printf("Próximo Número (-1 para sair):");
        scanf("%i", &input);
    }

    *final_size = size;
    return arr;
}


void print_array (int* arr, int size)
{
    for (int i = 0; i< size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
