//gets a point in a file and multiply both x and y by a factor

#include <stdio.h>

typedef struct p{
    int x;
    int y;
}point;

void multiplyPoint (int multiplyerFactor, int multipliePoint, char* filename);

int main ()
{
    char filename[] = "file1.bin";
    int multipliePoint = 2; // second point
    int multiplyerFactor = 3;

    multiplyPoint(multiplyerFactor, multipliePoint, filename);

    return 0;
}

void multiplyPoint (int factor, int position, char* filename)
{
    FILE * fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("Error to open file\n");
        return;
    }
    point pt;

    fseek(fp, (position - 1)*sizeof(point) , SEEK_SET);
    fread(&pt, sizeof(point), 1, fp);

    pt.x *= factor;
    pt.y *= factor;

    fseek(fp, (-1)*sizeof(point) , SEEK_CUR);
    fwrite(&pt, sizeof(point), 1, fp);
    fclose(fp);
}
