#include <stdio.h>
#include <string.h>

void invertWord(char *word, int SIZE);

int main ()
{
    char wrd[] = "Gustavo";

    int size = strlen(wrd);

    invertWord(wrd, size);

    printf("%s\n", wrd);
}

void invertWord(char* word, int SIZE)
{
    char temp[SIZE + 1];
    for (int i = 0; i < SIZE; i++)
    {
        temp[SIZE - i - 1] = word[i];
    }
    temp[SIZE] = '\0';
    strcpy(word, temp);
}
