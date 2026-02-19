#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* myRealloc ( void* srcblock, unsigned oldsize, unsigned newsize);

int main ()
{
    int size = 3;
    int new_size = 5;

    int* grades = (int*)malloc(size * sizeof(int));
    char* notes = (char*)malloc(size * sizeof(char));

    grades[0] =1;
    grades[1] =2;
    grades[2] =3;
    notes[0] ='H';
    notes[1] ='i';
    notes[2] ='!';

    grades = myRealloc(grades, size * sizeof(int), new_size *sizeof(int));
    for(int j = size; j < new_size; j++)
    {
        printf("Enter grade %i: ", j+1);
        scanf("%i", &grades[j]);
    }

    for (int n = 0; n < new_size; n++)
        printf("%i ", grades[n]);
    printf("\n");


    notes = myRealloc(notes, size * sizeof(char), (new_size+1) * sizeof(char));
    for(int p = size; p < new_size; p++)
    {
        printf("Enter note %i: ", p+1);
        scanf(" %c", &notes[p]);
    }
    for (int i = 0; i < new_size; i++)
        printf("%c", notes[i]);
    printf("\n");

    free(grades);
    free(notes);
    return 0;

}

void* myRealloc ( void* srcblock, unsigned oldsize, unsigned newsize)
{
    void* arr = (char*)malloc(newsize);
    if(!arr) return NULL;

    unsigned min = oldsize < newsize ? oldsize : newsize;
    memcpy(arr, srcblock, min);

    free(srcblock);
    return arr;
}

