// verifies if an array has a number with oposite sign neighbors. -> eg: neg - pos - neg

#include <stdio.h>

int oposite_sign(int *ptr , int size);

#define SIZE 5

int main ()
{
    int arr [SIZE] = {1, 2, 4 , 7, 9};

    if (oposite_sign(arr , SIZE))
    {
        printf("oposite neighbors\n");
        return 0;
    }
    printf("no oposite neighbors\n");
}

int oposite_sign(int *ptr , int size)
{
    if (size < 3)
        {
            return 0;
        }
    if (ptr[1] > 0 && ptr[0] < 0 && ptr[2] < 0)
        {
            return 1;
        }
    if (ptr[1] < 0 && ptr[0] > 0 && ptr[2] > 0)
        {
            return 1;
        }
    return oposite_sign (ptr+ 1, size - 1);
}

