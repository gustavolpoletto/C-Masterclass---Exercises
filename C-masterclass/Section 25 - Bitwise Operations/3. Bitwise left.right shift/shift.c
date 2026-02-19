#include <stdio.h>
// 10110010 move one to the left
// 0110010_

    // left shift bitwise operator (<<)
    // right shift bitwise operator (>>)
int main ()
{
    int value = 5;
    value = value << 1; //(00001010)
    printf("left- %i\n", value);
    value = value << 3; //(01010000)
    printf("      %i\n", value);

    value = 10; // 1010
    value = value >> 1; // 0101
    printf("right- %i\n", value);
    value = value >> 2; // 0001
    printf("       %i\n", value);


    value = 105;      // 01101001
    int mask = 1;    // 00000001
    mask = mask << 7; // 10000000

    for (int i = 0; i < 8; i++)
    {
        int result = mask & value;
        if(result != 0)
            printf("1");
        else
            printf("0");
        mask = mask >> 1;
    }
    printf("\n");
}
