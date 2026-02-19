// function recieves an array of integers, its size and some value "k"
// the array consists of values between "0" and "k"
// return 1 if the number of occurences of any value in the array is equals to the value itself

// eg: Arr: 1, 2, 2, 1, 4, 3 size = 6, k = 4
    //frequency 0 : 0 times; 1 : 2t ; 2 : 2t ; 3 and 4: 1t -> some are no equal - return 0;
// eg: Arr: 3, 2, 2, 1, 3, 3 size = 6, k = 3
    // 1 : 1; 2 : 2; 3 : 3; -> return 1;

#include <stdio.h>
#include <stdlib.h>

int FreqAsValue (int* Arr, const int size, const int k);

int main ()
{
    const int size = 6;
    //int Arr[size] = {1 , 2, 2, 1, 4, 3};
    int Arr[size] = {3 , 2, 2, 1, 3, 3};

    if(FreqAsValue(Arr, size, 3))
    {
        printf("The frequency is equals to all values\n");
        return 0;
    }

    printf("The frequency is different at some value\n");
    return 0;


}

int FreqAsValue (int* Arr, const int size, const int k)
{
    int* ptr = calloc(k + 1 , sizeof(int));
    if (ptr == NULL)
    {
        printf("error to alloc array");
        exit(0);
    }


    for(int i = 0; i < size; i++)
        ptr[Arr[i]]++;

    for(int j = 0; j <= k; j++)
    {
        if (j != ptr[j])
        {
            free(ptr);
            return 0;
        }
    }

    free(ptr);
    return 1;
}
