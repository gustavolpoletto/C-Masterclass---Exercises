#include <stdio.h>

    //And -> 1 keeps value  -> 0 sets to 0
int main()
{
    int value = 178; // 10110010
    int mask = 127; // 01111111
    int result = value & mask; // 00110010 -> turn of the first bit

    printf("%d\n", result);
}
