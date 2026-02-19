#include <stdio.h>
#include <string.h>

void invertWord(char *word, int size, char* temp, int SIZE);

int main ()
{

    char wrd[100];
    printf("Palavra para inverter ->");
    scanf("%99s", wrd);
    int size = strlen(wrd);
    int SIZE = size;
    char temp[size + 1];

    invertWord(wrd, size,temp, SIZE);

    printf("%s\n", wrd);
}

void invertWord(char* word, int size, char* temp, int SIZE)
{
    if (size == 0)
    {
        temp[SIZE]= '\0';
        strcpy(word, temp);
        return;
    }
    temp[SIZE- size] = word[size - 1];
    invertWord(word, size - 1, temp, SIZE);
}
