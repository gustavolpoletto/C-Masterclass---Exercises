#include <stdio.h>
#include <stdlib.h>

int** create2Darr(int rows, int columns);
void free2D(int** ptr, int rows);
void print2D (int** ptr, int column, int row);

int main()
{
    int** matrix;

    int rows;
    printf("rows: ");
    scanf("%i",&rows);

    int columns;
    printf("columns for rows: ");
    scanf("%i", &columns);

    matrix = create2Darr(rows, columns);
    print2D(matrix, columns, rows);
    free2D(matrix, rows);
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
        printf("%1d ", ptr[i][j]);
        }
        printf("\n");
    }
}

