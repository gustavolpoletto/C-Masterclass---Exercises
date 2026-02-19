// ({1,2}{3,4}{5,6}) -> ({5,6}{3,4}{1,2})
// with recursion
#include <stdio.h>

typedef struct p{
    int x;
    int y;
}point;


void addPoint (char* filename, point p);


int main ()
{
    char filename[] = "filePoint.bin";
    point p = {9, 10};

    addPoint (filename, p);

    return 0;
}

void addPoint (char* filename, point p)
{
    FILE* fp = fopen(filename, "ab"); //append in binary
    if (fp == NULL)
    {
        printf("error to open file\n");
        return;
    }
    
    fwrite(&p, sizeof(point), 1 , fp);
    fclose(fp);
}

