#include <stdio.h>

void swap(int* a, int* b);

int main ()
{
    int num1 = 5;
    int num2 = 7;

    swap(&num1, &num2);
    printf("1- %i  2- %i\n", num1, num2);

}

void swap(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}
