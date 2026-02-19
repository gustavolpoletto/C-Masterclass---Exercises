    //Bitwise rotatiion
// 10011001 >> 11001100 - shift putting the 'excluded' bit
#include <stdio.h>

void rightRotation (int* val);
void leftRotation (int* val);

int main ()
{
    int value1 = 10;
    int value2 = 10;

    rightRotation( &value1 );
    printf("%i\n", value1);

    leftRotation( &value2 );
    printf("%i\n", value2);

}

void rightRotation (int* val)
{
    int lastBit = *val & 1;
    *val = *val >> 1;
    if(lastBit == 1)
    {
        lastBit = lastBit << 7;
        *val = *val | lastBit;
    }
}

void leftRotation (int* val)
{
    int mask = 1 << 7;
    int firstBit = *val & mask;
    *val = *val << 1;
    if(firstBit == 1)
    {
        *val = *val | 1;
    }
}
