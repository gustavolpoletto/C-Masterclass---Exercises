//function recieves an array of integers ant its size - values between 0 and 'size'
// should return a specific value max sum
// eg: Arr {2, 1, 3, 2, 4, 2, 1} -> 1 apears 2 times -> 1*2 = 2 ; 2 apear 3 times 2*3 = 6

#include <stdio.h>
#include <stdlib.h>

int FindSpecificMaxSum (int* Arr, const int size);

int main ()
{
    const int size = 7;
    int Arr[size] = {2, 1, 3, 2, 4, 2, 1}; // should return 2
    //int Arr[size] = {2, 1, 3, 2, 4, 2, 7}; // should return 7

    int MaxSum = FindSpecificMaxSum(Arr, size);

    printf("number with most specific sum = %i\n", MaxSum);
    return 0;


}

int FindSpecificMaxSum (int* Arr, const int size)
{
    // crate an arr to count repetitions
    int* ptr = calloc(size + 1 , sizeof(int));
    if (ptr == NULL)
    {
        printf("error to alloc array");
        exit(0);
    }

    //create another array to count sum
    int* sum = calloc(size + 1 , sizeof(int));
    if (ptr == NULL)
    {
        printf("error to alloc array");
        exit(0);
    }

    //build count array - and atualizes the sum array
    for(int i = 0; i < size; i++)
    {
        ptr[Arr[i]]++;
        sum[Arr[i]] = ptr[Arr[i]] * Arr[i];
    }

    // find max sum
    int maxSum = 0;
    int maxSumIndex = 0;

    for(int k = 0; k <= size; k++)
    {
        if (sum[k] > maxSum)
        {
            maxSum = sum[k];
            maxSumIndex = k;
        }
    }

    //free arrays and return max sum value
    free(ptr);
    free(sum);
    return maxSumIndex;
}
