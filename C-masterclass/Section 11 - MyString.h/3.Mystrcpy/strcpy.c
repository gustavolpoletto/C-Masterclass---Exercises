#include <stdio.h>
#include <stdlib.h>

char* mystrcpy(char* orig);
int mystrlen (char* str);

int main()
{
    char original[]= "hello";

    char* copy = mystrcpy(original);
    printf("%s\n", copy);
}

char* mystrcpy(char* orig)
{
    int i = 0;
    int len = mystrlen(orig);
    char* cpy = malloc(len + 1);

    do{
        cpy[i] = orig[i];
        i++;
    }while(orig[i] != '\0');

    return cpy;
}

int mystrlen (char* str)
{
    int len = 0;

    while(str[len] != '\0')
        len++;

    return len;
}
