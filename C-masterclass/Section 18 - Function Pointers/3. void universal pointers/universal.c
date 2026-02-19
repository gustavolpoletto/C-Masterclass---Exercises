#include <stdio.h>

void printInt (void* a)
{
    printf("%2d ", *(int*)a);
}

void printFloat (void* a)
{
    printf("%.1f ", *(float*)a);
}

void performOperation(void* arr, int size, int elemSize, void(*printNum)(void*))
{
    for(int i = 0; i < size; i++)
    {
        printNum(arr + i * elemSize);
    }
}

int main()
{
    int IntArr[] = { 1 , 2 , 3};
    float FloatArr[] = {1.2 , 3.4 , 5.6};

    void(*printNum[])(void*) = {printInt, printFloat};

    performOperation(IntArr, 3, sizeof(int), printNum[0]);
    printf("\n");

    performOperation(FloatArr, 3, sizeof(float), printNum[1]);
    printf("\n");
}
