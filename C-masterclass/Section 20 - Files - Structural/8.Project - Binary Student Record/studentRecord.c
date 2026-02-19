#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char name [16];
    unsigned int totalGrades;
    double* grades;
}student;

student* createStudent (char*filename);
void printStudentDetails (student* student);
void saveStudentToFile (student* s, char* filename);
void ReadStudentRecord (char* studentName, char* filename);

int main ()
{
    char filename[] = "students.bin";
    student* student1 = createStudent(filename);
    // printStudentDetails(student1);

    ReadStudentRecord ("Abba", filename);

    free(student1->grades);
    free(student1);
    return 0;
}


student* createStudent (char*filename)
{
    student* std = malloc(sizeof(student));
    printf("Enter Student's name: ");
    scanf("%15s", std->name);
    printf("Enter number of grades: ");
    scanf("%u", &(std->totalGrades));

    std->grades = malloc(std->totalGrades * sizeof(double));

    for (int i = 0; i< std->totalGrades; i++)
    {
        printf("Enter grade #%i: ", i+1);
        scanf("%lf", &(std->grades[i]));
    }

    saveStudentToFile (std, filename);
    return std;
}

void printStudentDetails (student* student)
{
    printf("Student's name: %s\n", student->name);
    printf("Student's has %u grades\n", student->totalGrades);

    for (int i = 0; i < student->totalGrades; i++)
    {
        printf("grade #%i: %.2f\n", i+1, student->grades[i]);
    }

}

void saveStudentToFile (student* s, char* filename)
{
    FILE * fp = fopen(filename, "wb+");
    if (fp == NULL)
    {
        printf("error to open file");
        return;
    }
    fwrite (&(s->name), sizeof(char)*16, 1, fp);
    fwrite (&(s->totalGrades), sizeof(int), 1, fp);

    for (int i = 0; i < s->totalGrades; i++)
    {
        fwrite (&(s->grades[i]), sizeof(double), 1, fp);
    }

    fclose(fp);

}

void ReadStudentRecord (char* studentName, char* filename)
{
    char name[16];
    int totalGrades;
    double grade;

    FILE * fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("error to open the file to read");
        return;
    }


     while (fread(name, 16, 1, fp) == 1) {
        name[15] = '\0';

        fread(&totalGrades, sizeof(int), 1, fp);

        if (strcmp(name, studentName) == 0)
        {
            printf("name: %s\n", name);

            for (int i = 0; i < totalGrades; i++)
            {
                fread(&grade, sizeof(double), 1, fp);
                printf("grade #%d: %.2f\n", i + 1, grade);
            }
            break;
        }

        else
        {
            fseek(fp, totalGrades * sizeof(double), SEEK_CUR);
        }
    }

    fclose(fp);
    }

