// in a sorted array, find if there is a sum of 2 elements thats equal to received value
// optimized -> bigO_N;
#include <stdio.h>

int hasSum(int *ptr, int size, int expected_value, int* idx1, int*idx2);

#define SIZE 7

int main()
{
    int arr[SIZE] = {1,3,4,7,9,10,12};
    int index1 , index2, value;

    printf ("search sum:");
    scanf ("%i", &value);

    if (hasSum(arr, SIZE, value, &index1, &index2))
    {
        printf("the sum of %i° and %i° is the expected %i\n", index1, index2, value);
        return 0;
    }
    printf("No possible sum at the array\n");

}


int hasSum(int *ptr, int size, int expected_value, int* idx1, int*idx2)
{
    int a = 0;
    int b = size - 1;

    do
    {
        if (ptr[a] + ptr[b] < expected_value)
            {
                a++;
            }
        if (ptr[a] + ptr[b] > expected_value)
            {
                b--;
            }
        if (ptr[a] + ptr[b] == expected_value)
            {
                *idx1 = a + 1;
                *idx2= b + 1;
                return 1;
            }
    } while(a + 1 != b);

    return 0;
}
