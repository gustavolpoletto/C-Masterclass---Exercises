#include <stdio.h>

//prototype
int issorted(int *ptr , int size , int *ref);

#define SIZE 5

int main ()
{
    int ref1, ref2, ref3; // references -> check if is tottaly sorted

    int arr1[SIZE] = {1, 2, 5, 7, 10}; // totally sorted -> for every pair, left < right
    int arr2[SIZE] = {1, 2, 2, 5, 10};// sorted -> has equals numbers
    int arr3[SIZE] = {1, 2, 5, 3, 10}; // not sorted

    int a = issorted (arr1, SIZE, &ref1);
    int b = issorted (arr2, SIZE, &ref2);
    int c = issorted (arr3, SIZE, &ref3);

    char* finalresult[] = {"Not sorted" , "sorted" , "totally sorted"};

    int final1 = ref1 + a;
    int final2 = ref2 + b;
    int final3 = ref3 + c;



    printf("arr1 is %s\n", finalresult[final1]);
    printf("arr2 is %s\n", finalresult[final2]);
    printf("arr3 is %s\n", finalresult[final3]);
}

int issorted(int *ptr , int size , int *ref)
{
    for(int i = 0; i < SIZE - 1; i++)
    {
        if(ptr[i] > ptr[i+1])
        {
            *ref = 0;
            return 0;
        }
    }
    for (int i = 0; i < SIZE - 1; i++)
    {
        if(ptr[i] == ptr[i+1])
        {
            *ref = 0;
            return 1;
        }
    }
    *ref = 1;
    return 1;
}
