// file permissions - read . write . execute -> uodate what a file can or can't do

#include <stdio.h>

typedef struct Permissions{
    unsigned int read : 1;
    unsigned int write : 1;
    unsigned int execute : 1;
}permissions;

void printPermissions (permissions file);
void implementPermissions (permissions* file);

int main ()
{
    permissions filePermissions;
    implementPermissions(&filePermissions);
}

void implementPermissions (permissions* file)
{
    char x;
    printf("can the file be read? [Y] [N]\n");
    scanf(" %c", &x);
    if (x == 'Y' || x == 'y')
        file->read = 1;
    else
        file->read = 0;

    printf("can the file be written? [Y] [N]\n");
    scanf(" %c", &x);
    if (x == 'Y' || x == 'y')
        file->write = 1;
    else
        file->write = 0;

    printf("can the file be executed? [Y] [N]\n");
    scanf(" %c", &x);
    if (x == 'Y' || x == 'y')
        file->execute = 1;
    else
        file->execute = 0;

    printf("\n--Review permissions--\n");
    printPermissions (*file);

    printf("\nIt's all wright? [Y] [N]\n");
    scanf(" %c", &x);
     if (x == 'Y' || x == 'y')
        return;
    else
        implementPermissions(file);
}


void printPermissions (permissions file)
{
    if (file.read)
        printf("Can Read the file\n");
    else
        printf("Can't Read the file\n");

    if (file.write)
        printf("Can write at the file\n");
    else
        printf("Can't write at the file\n");

    if (file.execute)
        printf("Can execute the file\n");
    else
        printf("Can't execute the file\n");

}
