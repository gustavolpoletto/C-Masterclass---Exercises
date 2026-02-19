// receives an integer array and its size-> the values are between 0 and 'size'
// find and returns the dominant value (if exists) or return -1 -> number with appearence greater than half of the size of the array

#include <stdio.h>
#include <stdlib.h>

int HasDominantValue (int* Arr, const int size);

int main ()
{
    const int size = 5;
    int Arr[size] = {3, 5, 4, 3, 3}; // should return 3
    //int Arr[size] = {3 , 5, 1, 2, 3}; // should return -1

    int dom = HasDominantValue(Arr, size);

    if(dom == -1)
        printf("No domminant Values\n");

    else
        printf("Domminant Vallue = %i\n", dom);
    return 0;


}

int HasDominantValue (int* Arr, const int size)
{
    int* ptr = calloc(size + 1 , sizeof(int));
    if (ptr == NULL)
    {
        printf("error to alloc array");
        exit(0);
    }

    //build count array
    for(int i = 0; i < size; i++)
        ptr[Arr[i]]++;

    //search for a dominant value
    for(int j = 0; j <= size; j++)
    {
        if (ptr[j] > (size / 2))
        {
            free(ptr);
            return j;
        }
    }

    //return -1 if no dominant element was found
    free(ptr);
    return -1;
}
