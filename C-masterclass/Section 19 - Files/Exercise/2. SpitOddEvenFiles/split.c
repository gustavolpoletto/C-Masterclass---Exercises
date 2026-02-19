#include <stdio.h>

void splitOddEven (char* filename);

int main ()
{
    char filename[] = "0.numbers.txt";
    splitOddEven (filename);
}

void splitOddEven (char* filename)
{
    FILE* original = fopen(filename, "r");
    if(original == NULL)
        printf("Fail to open file");

    FILE* odd = fopen("1.odd.txt", "w");
    if(odd == NULL)
        printf("Fail to create odd");

    FILE* even = fopen("2.even.txt", "w");
    if(even == NULL)
        printf("Fail to create even");

    int num;

    while(fscanf(original, "%d", &num) != EOF)
    {
            if(num % 2 == 0)
                fprintf(even, "%d ", num);

            else
                fprintf(odd, "%d ", num);

    }
    fclose(odd);
    fclose(even);
    fclose(original);
}
