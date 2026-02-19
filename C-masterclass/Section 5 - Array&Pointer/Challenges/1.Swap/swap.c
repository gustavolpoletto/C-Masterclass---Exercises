#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap (int *num1 ,int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void swap_add (int *num1 ,int *num2)
{
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

void swap_mult (int *num1 ,int *num2)
{
    *num1 = *num1 * *num2;
    *num2 = *num1 / *num2;
    *num1 = *num1 / *num2;
}

void swap_generic (void *num1 ,void *num2 , int size)
{
    void *temp = malloc(size);
    memcpy (temp, num1, size);
    memcpy (num1, num2, size);
    memcpy (num2, temp, size);

    free(temp);

}

int main ()
{
    int a = 5;
    int b = 7;
    double g1 = 2.1;
    double g2 = 3.5;


    swap_mult(&a , &b);
    swap_generic (&g1, &g2, sizeof(g1));

    printf ("A apos a troca: %d\n", a);
    printf ("b apos a troca: %d\n", b);

    printf ("g1 apos a troca: %f\n", g1);
    printf ("g2 apos a troca: %f\n", g2);

    return 0;
}
