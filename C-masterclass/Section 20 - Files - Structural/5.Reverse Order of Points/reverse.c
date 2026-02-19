// ({1,2}{3,4}{5,6}) -> ({5,6}{3,4}{1,2})
// with recursion
#include <stdio.h>

typedef struct p{
    int x;
    int y;
}point;

void invertPoints (char* filename);
void resetFile (char* filename);
void invert(FILE* fp, int totalpoints, int curPosition);

int main ()
{
    char filename[] = "filePoint.bin";
    invertPoints(filename);
    // resetFile (filename); // in case of error or restart
}

void invertPoints (char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("error to open file\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    int totalPoints = ftell(fp) / sizeof(point);
    invert(fp, totalPoints, 0);
    fclose(fp);
}

void invert(FILE* fp, int totalpoints, int curPosition)
{
    point p1;
    point p2;
    if (curPosition < totalpoints)
    {
        fseek(fp, curPosition*sizeof(point), SEEK_SET);
        fread(&p1, sizeof(point), 1, fp);

        fseek(fp, (totalpoints-1)*sizeof(point), SEEK_SET);
        fread(&p2, sizeof(point), 1, fp);

        fseek(fp, curPosition*sizeof(point), SEEK_SET);
        fwrite(&p2, sizeof(point), 1, fp);

        fseek(fp, (totalpoints-1)*sizeof(point), SEEK_SET);
        fwrite(&p1, sizeof(point), 1, fp);

        invert(fp, totalpoints-1, curPosition+1);
    }
}

void resetFile (char* filename)

{
    point p1 = {1,2};
    point p2 = {3,4};
    point p3 = {5,6};
    point p4 = {7,8};

    FILE* f = fopen(filename, "wb+");
    fwrite(&p1, sizeof(point), 1, f);
    fwrite(&p2, sizeof(point), 1, f);
    fwrite(&p3, sizeof(point), 1, f);
    fwrite(&p4, sizeof(point), 1, f);


    fclose(f);
}
