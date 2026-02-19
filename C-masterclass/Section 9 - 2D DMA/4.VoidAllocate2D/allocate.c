// allocates a 2D array and pass by reference with a void type function

#include <stdio.h>
#include <stdlib.h>

void create2Darr(int*** ptr, int rows, int columns);
void free2D(int** ptr, int rows);
void print2D (int** ptr, int column, int row);

int main()
{
    int** matrix;

    int rows = 4;
    int columns = 4;

    create2Darr(&matrix, rows, columns);
    print2D(matrix, columns, rows);
    free2D(matrix, rows);
}

void create2Darr(int*** ptr, int rows, int columns)
{

    int** arr = calloc(rows, sizeof(int*));
    if(!arr) exit(1);

    for(int i = 0; i < rows; i++)
    {
        arr[i] = (int*)calloc(columns, sizeof(int));
        if (!arr[i])
        {
            free2D(arr, i);
            exit(1);
        }
    }
    *ptr = arr;
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
        printf("%1d ", ptr[i][j]);
        }
        printf("\n");
    }
}
