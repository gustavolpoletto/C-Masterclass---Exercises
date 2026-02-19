#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* grades;
    int* temp;
    int size, new_size;

    printf("Number of grades:");
    scanf("%d", &size);

    grades = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("Enter grade %i: ", i+1);
        scanf("%d", &grades[i]);
    }

    //adicionar notas

    new_size = size + 2;
    temp = (int*)realloc(grades, new_size*sizeof(int));
    if (temp != NULL)
        grades = temp;
    else
        return 1;
    printf("size = %i\n", new_size);
    for(int j = size; j < new_size; j++)
    {
        printf("Enter grade %i: ", j+1);
        scanf("%d", &grades[j]);
    }

    for(int c = 0; c < new_size; c++)
        printf("%d ", grades[c]);

    printf("\n");

    new_size = 2;

    printf("size = 2\n");

    temp = (int*)realloc(grades, new_size *sizeof(int));
    if (temp != NULL)
        grades = temp;
    else
        return 1;

    for(int n = 0; n < new_size; n++)
    {
        printf("%i ", grades[n]);
    }
    printf("\n");


    return 0;
}

