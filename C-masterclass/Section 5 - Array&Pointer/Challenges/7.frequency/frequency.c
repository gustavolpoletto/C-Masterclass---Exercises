#include <stdio.h>

#define SIZE 5

void frequency(int *ptr, int size);

int main()
{
    int arr[SIZE] = {5, 6, 7, 6, 5};

    frequency (arr, SIZE);
}

void frequency(int *ptr, int size)
{
    for(int i = 0;  i < size; i++)
    {
        int count = 1;
        for(int j = i; j < size; j++)
        {
            if(ptr[i] == ptr[j] && i != j)
            {
                count++;
            }
        }
        for(int m = 0; m < i; m++)
        {
            if(ptr[m] == ptr[i])
            {
                count = 0;
                break;
            }
        }
        if(count != 0)
        {
            printf("Number %i appears %i times\n", ptr[i], count);
        }
    }
}
