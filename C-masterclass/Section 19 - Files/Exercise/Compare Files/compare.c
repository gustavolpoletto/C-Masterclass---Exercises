// function - open and compare the content of two files
// true - is identical | false - not identical
#include <stdio.h>
#include <stdbool.h>

bool isIdentical (char* text1 , char* text2);

int main ()
{
    if (isIdentical("1text.txt" , "3text.txt"))
        printf("identical\n");
    else
        printf("different\n");
}

bool isIdentical (char* text1 , char* text2)
{
    FILE* fp1 = fopen(text1, "r");
    FILE* fp2 = fopen(text2, "r");

    char a, b;

    while(true)
    {
        a = fgetc(fp1);
        b = fgetc(fp2);

        if( a != b)
        {
            fclose(fp1);
            fclose(fp2);
            return false;
        }

        if (a == EOF)
            break;
    }
    fclose(fp1);
    fclose(fp2);
    return true;
}
