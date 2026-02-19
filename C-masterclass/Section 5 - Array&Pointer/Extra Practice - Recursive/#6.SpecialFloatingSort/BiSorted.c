// array of floating
// return 1 -> integer parts are sorted && decimal parts are in descending order *(1.4, 1.25 : 1 <= 1 , .4 >= .25)

#include <stdio.h>

int is_BiSorted (float* ptr, int size);

#define SIZE 3

int main ()
{
    float arr[SIZE] = { 1.4, 2.5, 4.1};

    if(is_BiSorted(arr, SIZE))
    {
        printf("Yeah\n");
        return 0;
    }


    printf("Nope\n");
}

int is_BiSorted (float* ptr, int size)
{
    if (size == 1)
        return 1;
    if ( (int)ptr[0] > (int)ptr[1] || (ptr[0] - (int)ptr[0]) < (ptr[1] - (int)ptr[1]))
        return 0;

    return is_BiSorted(ptr + 1, size -1);
}
