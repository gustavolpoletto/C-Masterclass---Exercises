#include <stdio.h>

    //toggle (invertion) -> 0 -> 1 || 1->0
    // XOR -> 0 mantains . 1 inverts
    // NOT(~) inverts all bits without mask
int main()
{
    int value = 178; // 10110010
    int mask = 127;  // 01000000
    int result = value ^ mask; // 11110010

    printf("%d\n", result);
}
