#include <stdio.h>

int mystrlen (char* str);
int mystrcmp (char* str1, char* str2);

int main()
{
    char str1[]= "hello";
    char str2[]= "helloworld";

    int compare = mystrcmp(str1, str2);
    printf("%i\n", compare);
}

int mystrcmp (char* str1, char* str2) //verifiesw whith words at same capitalization
{
    if(str1[0] == '\0' && str2[0] =='\0')
        return 0;

    else if(str1[0] == str2[0])
        return mystrcmp(str1+1, str2+1);

    else if(str1[0] > str2[0])
        return 1;

    else
        return -1;
}

int mystrlen (char* str)
{
    int len = 0;

    while(str[len] != '\0')
        len++;

    return len;
}
