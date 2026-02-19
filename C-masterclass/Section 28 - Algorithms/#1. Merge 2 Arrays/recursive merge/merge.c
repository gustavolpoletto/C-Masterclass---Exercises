#include <stdio.h>
#include <stdlib.h>

int * mergeFunction (int* a, int sizeA, int* b, int sizeB);
void merge (int* c, int sc, int* a, int sa, int* b, int sb);

int main ()
{
    const int s1 = 3, s2 = 4;
    int arrA [s1] = {2, 5, 8};
    int arrB [s2] = {1, 4, 9, 10};

    int * c = mergeFunction(arrA, s1, arrB, s2);

    for (int i = 0; i < s1+s2; i++)
    {
        printf("%i ", c[i]);
    }
    printf("\n");

    free(c);
    return 0;
}

int * mergeFunction (int* a, int sizeA, int* b, int sizeB)
{

    int sizeC = sizeA + sizeB;
    int* c = malloc(sizeof(int) * sizeC);

    merge(c, sizeC, a, sizeA, b, sizeB);

    return c;
}

void merge (int* c, int sc, int* a, int sa, int* b, int sb)
{
    int i;
    if (sa == 0)
    {
        for (i = 0; i < sc; i++)
        {
            c[i] = b[i];
        }
        return;
    }

    if (sb == 0)
    {
        for (i = 0; i < sc; i++)
        {
            c[i] = a[i];
        }
        return;
    }

    if (*a < *b)
    {
        c[0] = a[0];
        merge(c+1, sc-1, a+1, sa-1, b, sb);
    }
    else
    {
        c[0] = b[0];
        merge(c+1, sc-1, a, sa, b+1, sb-1);
    }
}

