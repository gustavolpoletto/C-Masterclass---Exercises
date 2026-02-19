#include <stdio.h>
#include <stdlib.h>


int main ()
{
    int i = 0, j=0, k=0;
    const int s1 = 3, s2 = 4;

    //inicialize arrays
    int arrA [s1] = {2, 5, 8};
    int arrB [s2] = {1, 4, 9, 10};

    int arrC[s1+s2];

    //merge
    while(i < s1 && j< s2)
    {
        if(arrA[i] < arrB[j])
            arrC[k++] = arrA[i++];
        else
            arrC[k++] = arrB[j++];
    }

    while ( i < s1)
    {
        arrC[k++] = arrA[i++];
    }
    while ( j < s2)
        arrC[k++] = arrB[j++];

    //print merged array
    for (int p = 0; p < s1+s2; p++)
    {
        printf("%i ", arrC[p]);
    }
    printf("\n");

    return 0;
}

