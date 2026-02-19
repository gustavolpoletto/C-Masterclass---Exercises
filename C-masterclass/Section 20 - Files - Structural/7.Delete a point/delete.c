#include <stdio.h>

typedef struct p{
    int x;
    int y;
}point;

void deletePoint(point p, char* filename);
void resetFile (char* filename);

int main ()
{
    point p1 = {3,4}; // valid point to delete
    point p2 = {8,9}; // non-existent point

    deletePoint(p1, "fileDel.bin");
    // resetFile("fileDel.bin");

    return 0;
}

void deletePoint(point p, char* filename)
{
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("error to open file\n");
        return;
    }

    FILE* temp = fopen("temp.bin", "wb");
    if (fp == NULL)
    {
        printf("error to open temporary file\n");
        return;
    }

    point buffer;

    while(fread(&buffer,sizeof(point), 1, fp) == 1)
    {
        if(buffer.x != p.x || buffer.y != p.y)
        {
            fwrite(&buffer, sizeof(point), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.bin", filename);


}

void resetFile (char* filename)

{
    point pArr[] = {{1,2},{3,4},{5,6},{7,8}};

    FILE* f = fopen(filename, "wb+");
    for(int i = 0; i < 4; i++)
    {
        fwrite(&pArr[i], sizeof(point), 1, f);
    }
    fclose(f);
}

