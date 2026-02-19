#include <stdio.h>
// OR x or 0 = x ; 1 or x = 1

/*
int main()
{
    int value = 5;  //00000101
    int mask = 126; // 10000000
    int result = value | mask; // 1...(keeps the value)
    // result = 10000101
}
*/


    //0x00x00x x must be one // turned on
int main()
{
    int value = 5;  //00000101
    int mask = 73; // 01001001
    int result = value | mask;  (01001101)
}

