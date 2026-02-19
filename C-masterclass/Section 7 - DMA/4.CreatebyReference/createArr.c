#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_arr (int**ptr, unsigned final_size);
void print_array (int* arr, int size);

int main(){
    int* arr = NULL;
    int size;
    do{
    printf("Enter desired size:");
    scanf("%i", &size);
    }while (size <= 0);

    create_arr(&arr, size);
    print_array(arr, size);

}

void create_arr (int**ptr, unsigned final_size)
{
    *ptr = (int*)malloc(final_size * sizeof(int));

    for (int i = 0; i < final_size; i++)
    {
        printf("Enter value %i:", i + 1);
        scanf("%i", &(*ptr)[i]);
    }
}


void print_array (int* arr, int size)
{
    for (int i = 0; i< size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
