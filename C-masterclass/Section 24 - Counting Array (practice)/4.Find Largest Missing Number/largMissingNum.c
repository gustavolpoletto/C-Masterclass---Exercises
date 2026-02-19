//function recieve an array of integers and its size - values between 0 and 'n'
//should return the largest missing value in the array (<=n)
// {2, 1, 3, 2, 4, 2, 7} size=7 -> should return 6
// {2, 1, 2, 4, 5, 6, 7} size=7 -> should return 3


#include <stdio.h>
#include <stdlib.h>

int FindLargestMissingNum (int* Arr, const int size);

int main ()
{
    const int size = 7;
    //int Arr[size] = {2, 1, 3, 2, 4, 2, 7}; // should return 6
    int Arr[size] = {2, 1, 2, 4, 5, 6, 7}; // should return 3

    int largMissing = FindLargestMissingNum(Arr, size);

    printf("largest missing numum = %i\n", largMissing);
    return 0;


}

int FindLargestMissingNum (int* Arr, const int size)
{
    // crate an arr to count repetitions
    int* ptr = calloc(size + 1 , sizeof(int));
    if (ptr == NULL)
    {
        printf("error to alloc array");
        exit(0);
    }

    //build count array
    for(int i = 0; i < size; i++)
    {
        ptr[Arr[i]]++;
    }

    // find max missing num

    for(int k = size; k >= 0; k--)
    {
        if (ptr[k] == 0 )
        {
            free(ptr);
            return k;
        }
    }

    //if no value was found there is an error,  at array size , logic error...
    free(ptr);
    return -1;
}
