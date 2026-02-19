#include <stdio.h>

#define SIZE 5


int is_palindrome (int *ptr , int size);

int main ()
{
    int arr[SIZE] = {1, 2, 5,  12,};


    if (is_palindrome(arr, SIZE))
    {
        printf("is palindrome\n");
        return 0;
    }
    printf("is not a palindrome\n");
}

int is_palindrome (int *ptr , int size)
{

    if (ptr[0] != ptr[size - 1])
    {
        return 0;
    }

    if (size <=1)
    {
        return 1;
    }

    return is_palindrome(ptr + 1, size-2);
}
