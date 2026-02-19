/* main program (main function) should create a school, populate it with courses and
students, and then print the details of the entire school. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Student Struct: Each student in the school has their own unique record, containing details like name and ID
typedef struct Student{
    char name[10];
    int id;
    unsigned int grade;
}student;

// Course Struct: Each course offered in the school will have its own struct. This includes the course name, average grade, and a dynamic array of enrolled students.
typedef struct Course{
    char course_name[10];
    float avr_grade;
    unsigned int tot_students;
    student* enrolled;
}course;

// School Struct: This struct encapsulates all the courses offered in the school, making up the whole school system. This struct should include
typedef struct School{
    char school_name[20];
    unsigned int num_courses;
    course* courses_offered;
}school;

//Prototypes =D
student* createStudent();
course* createCourse ();
school* createSchool ();
void printStudentDetails(student* std);
void printCourseDetails (course* course);
void printSchoolDetails(school* school);
int checkStudentinCourse (int id, course* course);
int checkStudentinSchool (int id, school* school);
void printStudentCourses (int id, school* school);
void printStudentsFail (course* course, double cutOffGrade);
void printStudentsPass (course* course, double cutOffGrade);
void printPassedGrade (school* school, double grade);
void printFailedGrade (school* school, double grade);
void AverageGrade (school* school);
void highAvrGrade (school* school);
void freeSchool (school* school);
void upgradeStudentGrade(course* course, unsigned int studentID, unsigned int newGrade);
void updateStudentName (course* course, unsigned int studentID, char* newName);
bool isCourseinSchool (school* school, char* CourseName);
void updateCourseName (course* course, char* newName);
void CommonCoursesBetweenSchools (school* school1, school* school2);
void CoursesOnlyAtOneSchool (school* school1, school* school2);

// Main Program
int main ()
{
    //Creates a new school
    school* FirstSchool = createSchool();

    //Uses functions to print some details
    printSchoolDetails(FirstSchool);

    printStudentCourses(123 , FirstSchool);

    printStudentsFail(&(FirstSchool->courses_offered[0]) , 60.0);
    printStudentsPass(&(FirstSchool->courses_offered[0]) , 60.0);

    freeSchool(FirstSchool);
}

/* --- Functions to Implement ---*/

// Create a Student: Takes user input for student details, allocates a new student struct in memory, and populates the struct with the provided details.
student* createStudent()
{
    student* newStudent = malloc(sizeof(student));
    if (!newStudent)
    {
        printf("Error to create a new student\n");
        return NULL;
    }

    printf("Student Name: ");
    scanf("%9s", newStudent->name);
    printf("ID: ");
    scanf("%i", &(newStudent->id));
    printf("Grade: ");
    scanf("%u", &(newStudent->grade));

    return newStudent;
}

// Create a Course: Asks for the number of students in a course and their details. Allocates a new course struct in memory, and populates it with the provided course details and students.
course* createCourse ()
{
    course* newCourse = malloc(sizeof(course));
    if (!newCourse)
    {
        printf("Error to create a new course\n");
        return NULL;
    }

    printf("Course Name: ");
    scanf("%9s", newCourse->course_name);
    printf("Total Students: ");
    scanf("%u", &(newCourse->tot_students));

    newCourse->enrolled = malloc((newCourse->tot_students) * sizeof(student));
    if (!newCourse->enrolled)
    {
        printf("Error to allocate students\n");
        return NULL;
    }

    //fill students in course
    for(int i = 0; i < newCourse->tot_students; i++)
    {
        printf("Enter details for student #%d\n", i + 1);
        student* temp = createStudent();
        if (!temp) {
            printf("Failed to create student\n");
            exit(1);
        }
        newCourse->enrolled[i] = *temp;
        free(temp);
    }
    //make average grade
    int sumgrades = 0;
    for(int i = 0; i < newCourse->tot_students; i++)
    {
        sumgrades += newCourse->enrolled[i].grade;
    }
    printf("Sumgrades: %i\n", sumgrades);
    printf("tot students: %i\n", newCourse->tot_students);
    if (newCourse->tot_students > 0)
        newCourse->avr_grade = (float)sumgrades / newCourse->tot_students;
    else
        newCourse->avr_grade = 0.0f;


    return newCourse;
}

// Create a School: Takes user input for the number of courses and their details. Allocates a new school struct in memory, and populates it with the provided details.
school* createSchool ()
{
    school* newSchool = malloc(sizeof(school));
    if (!newSchool)
    {
        printf("Error to create a new school\n");
        return NULL;
    }
    printf("School Name: ");
    scanf("%19s", newSchool->school_name);
    printf("Number of Courses: ");
    scanf("%u", &(newSchool->num_courses));

    newSchool->courses_offered = malloc(newSchool->num_courses * sizeof(course));
    if (!newSchool->courses_offered)
    {
        printf("Error to allocate students\n");
        return NULL;
    }

    //fill courses
    for(int i = 0; i < newSchool->num_courses; i++)
    {
        printf("Enter details for course #%d\n", i + 1);
        course* temp = createCourse();
        newSchool->courses_offered[i] = *temp;
        free(temp);
    }

    return newSchool;
}

// Print Student Details: Takes a student struct and prints its details.
void printStudentDetails(student* std)
{
    printf("student name: %s\n", std->name);
    printf("student id: %i\n", std->id);
    printf("student grade: %i\n", std->grade);
}

// Print Course Details: Accepts a course struct and prints the details of the course and the students enrolled in it.
void printCourseDetails (course* course)
{
    printf("course name: %s\n", course->course_name);
    printf("course average grade: %f\n", course->avr_grade);
    printf("course students: %i\n", course->tot_students);
    for (int i = 0; i < course->tot_students; i++)
    {
        printf("enrolled student #%i: \n", i+1);
        printStudentDetails(&(course->enrolled[i]));
    }
}

// Print School Details: Takes a school struct and prints the school's details, all the courses offered, and the students in those courses.
void printSchoolDetails(school* school)
{
    printf("\n");
    printf("--SCHOOL DETAILS--\n");
    printf("school name: %s\n", school->school_name);
    printf("total offered courses: %i\n", school->num_courses);
    for (int i = 0; i < school->num_courses; i++)
    {
        printf("course #%i: \n", i+1);
        printCourseDetails(&(school->courses_offered[i]));
    }
}

// Check if student in course: Takes a student's ID and a course struct, iterates over the course's student list, and checks if the student is enrolled.
int checkStudentinCourse (int id, course* course)
{
    for(int i = 0; i < course->tot_students; i++)
    {
        if(course->enrolled[i].id == id)
        {
            return 1;
        }
    }
    return 0;
}

// Check if student in school: Accepts a student's ID and a school struct. It uses the previous function to check if the student is enrolled in any of the school's courses.
int checkStudentinSchool (int id, school* school)
{
    for(int i = 0; i < school->num_courses; i++)
    {
        if(checkStudentinCourse(id, &(school->courses_offered[i])))
        {
            return 1;
        }
    }
    return 0;
}

// Print all student courses: Receives a student's ID and a school struct. It prints out all the courses that the student is enrolled in.
void printStudentCourses (int id, school* school)
{
    for(int i = 0; i < school->num_courses; i++)
    {
        if (checkStudentinCourse(id, &(school->courses_offered[i])))
            printf("enrolled in course: %s\n", school->courses_offered[i].course_name);
    }
}

// Print all students who failed a course: Accepts a course struct and a passing grade. Prints the details of students who didn't meet the passing grade.
void printStudentsFail (course* course, double cutOffGrade)
{
    printf("students who fail in %s\n", course->course_name);
    for(int i = 0; i < course->tot_students; i++)
    {
        if(course->enrolled[i].grade < cutOffGrade)
            printf(" -%s  -g: %d\n", course->enrolled[i].name, course->enrolled[i].grade);
    }
}

// Print all students who passed a course: Similar to the previous function but prints details of students who have met or exceeded the passing grade.
void printStudentsPass (course* course, double cutOffGrade)
{
    printf("students who passed in %s\n", course->course_name);
    for(int i = 0; i < course->tot_students; i++)
    {
        if(course->enrolled[i].grade >= cutOffGrade)
            printf(" -%s  -g: %d\n", course->enrolled[i].name, course->enrolled[i].grade);
    }
}

// Print all the courses with a passed average grade: Receives a school struct and a passing grade. Prints out courses where the average grade is equal to or higher than the passing grade.
void printPassedGrade (school* school, double grade)
{
    printf("courses with passing grade:\n");
    {
        for(int i = 0; i < school->num_courses; i++)
        {
            if(school->courses_offered[i].avr_grade >= grade)
            {
                printf("-%s\n",school->courses_offered[i].course_name);
            }
        }
    }
}

// Print all the courses with a failed average grade: Similar to the previous function but prints out courses where the average grade is below the passing grade
void printFailedGrade (school* school, double grade)
{
    printf("courses with failing grade:\n");
    {
        for(int i = 0; i < school->num_courses; i++)
        {
            if(school->courses_offered[i].avr_grade < grade)
            {
                printf("-%s\n",school->courses_offered[i].course_name);
            }
        }
    }
}

// Print the average grade between all the courses: Accepts a school struct, calculates the average grade for each course, then calculates and prints the overall average of these averages.
void AverageGrade (school* school)
{
    double sum = 0;
    for (int i = 0; i < school->num_courses; i++)
    {
        sum += school->courses_offered[i].avr_grade;
    }
    double avr = sum / school->num_courses;

    printf("Average grade of between courses: %.2f\n", avr);
}

// Print the course with the highest average grade: Receives a school struct, finds the course with the highest average grade, and prints its details
void highAvrGrade (school* school)
{
    course* highGradeCourse = &(school->courses_offered[0]);
    for (int i = 1; i < school->num_courses; i++)
    {
        if(school->courses_offered[i].avr_grade > highGradeCourse->avr_grade)
            highGradeCourse = &(school->courses_offered[i]);
    }
    printf("Course with highest Average Grade:\n");
    printCourseDetails (highGradeCourse);
}

void freeSchool (school* school)
{
    for(int i = 0; i < school->num_courses; i++)
    {
        free(school->courses_offered[i].enrolled);
    }
    free(school->courses_offered);
    free(school);
}

//Updating a student grade
void upgradeStudentGrade(course* course, unsigned int studentID, unsigned int newGrade)
{
    for (int i = 0; i < course->tot_students; i++)
    {
        if (studentID == course->enrolled[i].id)
        {
            course->enrolled[i].grade = newGrade;

            //update the average grade of the course
        int sumgrades = 0;
        for(int j = 0; j < course->tot_students; j++)
        {
            sumgrades += course->enrolled[j].grade;
        }
        if (newCourse->tot_students > 0)
            newCourse->avr_grade = (float)sumgrades / newCourse->tot_students;
        else
            newCourse->avr_grade = 0.0f;

            return;
        }
    }
    printf("student not found\n");
}

//Updating a student name
void updateStudentName (course* course, unsigned int studentID, char* newName)
{
    for (int i = 0; i < course->tot_students; i++)
    {
        if (studentID == course->enrolled[i].id)
        {
            strncpy(course->enrolled[i].name, newName, 9);
            course->enrolled[i].name[9] = '\0';
        }

    }
}

//return boolean- is course in school?
bool isCourseinSchool (school* school, char* CourseName)
{
    for (int i = 0; i < school->num_courses; i++)
    {
        if (strcmp(school->courses_offered[i].course_name, CourseName) == 0)
            return true;
    }
    return false;
}

//updating Course name
void updateCourseName (course* course, char* newName)
{
    strcpy(course->course_name, newName);
}

//Printing common courses between schools
void CommonCoursesBetweenSchools (school* school1, school* school2)
{
    printf("common courses between %s and %s\n", school1->school_name, school2->school_name);
    for (int i = 0; i < school1->num_courses; i++)
    {
        if(isCourseinSchool(school2, school1->courses_offered[i].course_name))
            printf("-%s\n",school1->courses_offered[i].course_name);
    }
}

//Printing courses that are in one school but not in the other
void CoursesOnlyAtOneSchool (school* school1, school* school2)
{
    printf("Courses only at %s\n", school1->school_name);
    for (int i = 0; i < school1->num_courses; i++)
    {
        if(!isCourseinSchool(school2, school1->courses_offered[i].course_name))
            printf("-%s\n",school1->courses_offered[i].course_name);
    }

    printf("Courses only at %s\n", school2->school_name);
    for (int j = 0; j < school2->num_courses; j++)
    {
        if(!isCourseinSchool(school1, school2->courses_offered[j].course_name))
            printf("-%s\n",school2->courses_offered[j].course_name);
    }
}
