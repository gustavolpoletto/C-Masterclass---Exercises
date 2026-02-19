#include <stdio.h>

int mystrlen (char* str);

int main()
{
    char str[]= "hello";

    int len = mystrlen(str);
    printf("%i\n", len);
}

int mystrlen (char* str)
{
    int len = 0;

    while(str[len] != '\0')
        len++;

    return len;
}
