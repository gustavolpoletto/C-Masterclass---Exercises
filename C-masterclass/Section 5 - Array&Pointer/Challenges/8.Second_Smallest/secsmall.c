#include <stdio.h>

void second_smallest(int *ptr , int size);
int find_smallest(int *ptr, int size);


#define SIZE 5

int main ()
{
    int arr[SIZE] = {100, 85, 39, 21, 39 };

    second_smallest(arr , SIZE);
}

void second_smallest(int *ptr , int size)
{
    int smallest = find_smallest(ptr, size);
    int s_small;

    for(int i = 0; i < size; i++)
    {
        if (smallest != ptr[i])
        {
            s_small = ptr[i];
            break;
        }
        printf("Todos os números são iguais\n");
        return;
    }
    for(int j = 0; j < size; j++)
    {
        if (ptr[j] < s_small && ptr[j] != smallest )
        {
            s_small = ptr[j];
        }

    }
        printf("second smallest -> %i\n", s_small);
}

int find_smallest(int *ptr, int size)
{
    int small = ptr[0];
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] < small)
        {
            small = ptr[i];
        }
    }
    return small;
}
