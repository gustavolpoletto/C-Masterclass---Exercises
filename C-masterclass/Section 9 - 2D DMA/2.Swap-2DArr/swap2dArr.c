// function1 -> universally swap 2 rows O(1)
// function2 -> swap 2 columns O(n)

#include <stdio.h>
#include <stdlib.h>

//Prototypes
int** create2Darr(int rows, int columns);
void free2D(int** ptr, int rows);
void print2D (int** ptr, int column, int row);
void fillArr(int** ptr, int row, int column);
void swapRow (void** ptr);
void swapColumn(int** ptr, int rows);

int main()
{
    int** matrix;

    int rows = 3;
    int columns = 3;

    matrix = create2Darr(rows, columns);
    fillArr(matrix, rows, columns);
    swapRow((void**)matrix);
    swapColumn(matrix, rows);
    print2D(matrix, columns, rows);
    free2D(matrix, rows);
}

void swapColumn(int** ptr, int total_rows)
{
    //swap columns 0 and 2
    int temp;
    for(int i = 0; i < total_rows; i++)
    {
        temp = ptr[i][0];
        ptr[i][0] = ptr[i][2];
        ptr[i][2] = temp;
    }

}
void swapRow (void** ptr)
{
    // swap rows 0 and 2 -> could be an input
    void* temp = NULL;
    temp = ptr[0];
    ptr[0] = ptr[2];
    ptr[2] = temp;
}


void fillArr(int** ptr, int row, int column)
{
    for(int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            ptr[i][j]= i*10 + j;
        }
    }
}

int** create2Darr(int rows, int columns)
{

    int** arr = calloc(rows, sizeof(int*));
    if(!arr) return NULL;

    for(int i = 0; i < rows; i++)
    {
        arr[i] = (int*)calloc(columns, sizeof(int));
        if (!arr[i])
        {
            free2D(arr, i);
            return NULL;
        }
    }
    return arr;
}

void free2D(int** ptr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(ptr[i]);
    }
    free(ptr);
}

void print2D (int** ptr, int column, int row)
{
    for(int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
        printf("%2i ", ptr[i][j]);
        }
        printf("\n");
    }
}
