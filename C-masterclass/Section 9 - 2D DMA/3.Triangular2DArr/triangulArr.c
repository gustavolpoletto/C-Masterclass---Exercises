//function 1 - return lower triangular matrix
//function 2 - return upper triangular matrix

#include <stdio.h>
#include <stdlib.h>

//Prototypes
void free2D(int** ptr, int rows);
int** lowerTriangular (int len);
int** upperTriangular (int len);
void print2Dlower (int** ptr, int len);
void print2Dupper (int** ptr, int len);

int main()
{
    int** lower;
    int** upper;
    int trianglen = 3; //how many spaces at the base

    //creates both triangulars arrays
    lower = lowerTriangular(trianglen);
    upper = upperTriangular(trianglen);

    //show and free lower one
    printf("lower\n");
    print2Dlower(lower, trianglen);
    free2D(lower, trianglen);

    //print and free upper
    printf("upper\n");
    print2Dupper(upper, trianglen);
    free2D(upper, trianglen);
}

int** upperTriangular (int len)
{
   int** arr = malloc(len * sizeof(int*));

   for (int i = 0; i < len; i++)
   {
        arr[i] = calloc(len - i, sizeof(int));
        for (int j = 0 ; j < len - i; j++)
        {
            arr[i][j] = 1;

        } // just to inicialize a value - could maintain 0
   }
   return arr;
}

int** lowerTriangular (int len)
{
   int** arr = malloc(len * sizeof(int*));

   for (int i = 0; i < len; i++)
   {
        arr[i] = calloc(i + 1, sizeof(int));
        for (int j = 0; j <= i; j++)
        {
            arr[i][j] = (i == j) ? 2 : 1;
        }
   }
   return arr;
}

void free2D(int** ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        free(ptr[i]);
    }
    free(ptr);
}

void print2Dlower (int** ptr, int len)
{
    for(int i = 0; i < len; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%2i ", ptr[i][j]);
        }
        printf("\n");
    }
}

void print2Dupper (int** ptr, int len)
{
        for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            printf("%2i ", ptr[i][j]);
        }
        printf("\n");
    }
}
