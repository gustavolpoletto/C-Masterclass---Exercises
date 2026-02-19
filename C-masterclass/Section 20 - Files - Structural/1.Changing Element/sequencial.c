// Changing an item in a file, whithount messing with formating

#include <string.h>
#include <stdio.h>

void changeCountry (char* filename , char* newstr , char* person);

int main()
{
    changeCountry("user.txt" , "Brazil" , "Christina");
}

void changeCountry (char* filename, char* newcountry , char* person)
{
    FILE * fp = fopen (filename, "r");
    FILE * temp = fopen ("temp.txt" , "w");

    int personalNumber;
    char name[20];
    char country[20];
    int age;

    while (fscanf(fp , "%i %s %s %i", &personalNumber, name, country, &age) != EOF)
    {
        if(strcmp(name , person) != 0)
        {
            fprintf(temp ,"%i %s %s %i\n", personalNumber, name, country, age);
        }
        else
        {
            fprintf(temp ,"%i %s %s %i\n", personalNumber, name, newcountry, age);
        }
    }
    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt" , filename);

}
