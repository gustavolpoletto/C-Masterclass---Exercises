// verifica se a soma dos dois vizinhos é igual ao item do array

#include <stdio.h>

#define SIZE 5

int neighbors(int *arr, int size)
{
    for (int i = 1; i < size - 1 ; i++)
    {
        if (arr[i] == arr[i-1] + arr[i+1])
        {
            return 1;
        }
    }
    return 0;
}

int main ()
{
    int array1 [SIZE] = {1, 4, 7, 3, 2}; // -> return 1 (4 + 3 = 7)
    int array2 [SIZE] = {1, 4, 1, 4, 2}; // -> return 0

    int rsp1 = neighbors(array1, SIZE);
    int rsp2 = neighbors(array2, SIZE);

    printf("resultado 1 = %i, resultado 2 = %i\n", rsp1, rsp2);
}
