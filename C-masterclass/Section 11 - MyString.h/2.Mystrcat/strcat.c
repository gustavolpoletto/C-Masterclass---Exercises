#include <stdio.h>
#include <stdlib.h>

int mystrlen (char* str);
char* mystrcat (char* str1, char* str2);

int main()
{
    char str1[]= "Hello";
    char str2[]= "World";

    char* concat = mystrcat(str1, str2);
    printf("%s\n", concat);
}

char* mystrcat (char* str1, char* str2)
{
    int len1 = mystrlen(str1);
    int len2 = mystrlen(str2);

    char* cat = malloc(len1 + len2 + 1);
    if (!cat) return NULL;

    for(int i = 0; i < len1; i++)
        cat[i] = str1[i];

    for(int j = 0; j < len2; j++)
        cat[j + len1] = str2[j];

    cat[len1 + len2] = '\0';

    return cat;
}

int mystrlen (char* str)
{
    int len = 0;

    while(str[len] != '\0')
        len++;

    return len;
}
