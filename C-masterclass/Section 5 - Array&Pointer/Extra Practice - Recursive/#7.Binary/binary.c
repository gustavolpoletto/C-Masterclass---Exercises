//shows the binary representstion of a number

#include <stdio.h>

int transform_binary(int num);
void recursive_binary (int num);

int main()
{
    int num;

    printf("number -> binary:");
    scanf("%i", &num);

    recursive_binary (num);
    printf("\n");

    int binary = transform_binary(num);

    printf("binary: %i\n", binary);
}

int transform_binary(int num)
{
    int num_now = num;
    int inicial = num;
    int binary = 0;
    int count = 0;
    int track = 1;
    int decimal = 1;
    int binary_now = 0;
    do{
        count = 0;
        track = 1;
        decimal = 1;

        do{
            count ++;
            track = track * 2;
        }
        while (track <= num_now);

        for (int i= 1; i < count; i++)
            decimal = decimal * 10;

        binary = binary + decimal;
        num_now = num_now - track / 2;
        binary_now = binary_now + track/ 2;

    } while (inicial != binary_now);

    return binary;
}

// Recursive (right) way

void recursive_binary (int num)
{
    if (num != 0){
        recursive_binary(num / 2);
        printf("%i", num % 2);
    }
}
