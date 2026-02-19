#include <stdio.h>
/*
    // Right Most Digit
int main()
{
    int value = 30;
    int mask = 1; // 00000001
    int result = value & mask; // 0000000X
    // AND -> all zero's in mask will remain - and the rightmost will depend, be equal to the last bit of the value
    // result 0 - rightmost = 0 || result 1 - rightmost = 1
    if (result == 0)
    printf("rightmostdigit = 0\n");
    else
    printf("rightmostdigit = 1\n");
}
*/

/*
    // Left Most Digit
int main()
{
    int value = 35000;
    int mask = 32768; // 10000000
    int result = value & mask;

    if (result == 0)
    printf("leftmostdigit = 0\n");
    else
    printf("leftmostdigit = 1\n");
}
*/

/*
// Second Right Most Digit
int main()
{
    int value = 6;
    int mask = 2; // 00000010
    int result = value & mask;

    if (result == 0)
    printf("Second Right mostdigit = 0\n");
    else
    printf("Second Right mostdigit = 1\n");
}
*/

    //More than one digit
int main()
{
    int value = 3;
    int mask = 34; // 00100010
    int result = value & mask;

    if (result == mask)
        printf("Both Bits are 1\n");
    else if (result != 0)
        printf("One bit is 1 other 0\n");
    else
        printf("Both are 0\n");
}
