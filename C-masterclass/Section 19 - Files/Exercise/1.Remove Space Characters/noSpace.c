//Function showld recieve an iput filename, read and remove all space characters
// and create an output file with same content without spaces

#include <stdio.h>

void removeSpaces (char *original ,char* newFile );

int main()
{
    char originalFileName[] = "file.txt";
    char newFileName[] = "Output.txt";
    removeSpaces (originalFileName, newFileName);

}

void removeSpaces (char *originalName ,char* newFileName )
{
    FILE* originalFile = fopen(originalName , "r");
    FILE* noSpaces = fopen(newFileName, "w");
    char c;

    if(originalFile != NULL && noSpaces != NULL)
    {
        while(!feof(originalFile)) // !not (File) End Of File
        {
            c = fgetc(originalFile);
            if (c != ' ')
                fputc(c , noSpaces);

            }
        }
    if(originalFile != NULL)
        fclose(originalFile);
    if(noSpaces != NULL)
        fclose(noSpaces);
}

