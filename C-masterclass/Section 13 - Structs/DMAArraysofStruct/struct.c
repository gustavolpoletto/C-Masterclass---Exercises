/* two functions that allocate dinamycally an array of employee and reads inputs for each of the elements
 - 1 - returns the array
 - 2 - pass the pointer by reference */

#include <stdio.h>
#include <stdlib.h>


typedef struct employee {
	char name[10];
	float age;
	int id;
}employee;

void printEmployee (employee* emp, int size);
employee* createarrayStruct(int size);
void passArrayStruct(employee** ptr, int size);

int main()
{
	int size;
	printf("Number of Employees:");
	scanf("%i", &size);

	employee* people = createarrayStruct(size);
	printEmployee(people, size);

	printf("----\n");

	employee* ptrArr;
	 passArrayStruct(&ptrArr, size);
	 printEmployee(ptrArr, size);

}

void printEmployee (employee* emp, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Employee #%d = name:%s, age:%.2f, id: %i\n", i + 1, emp[i].name, emp[i].age, emp[i].id);
	}
}

employee* createarrayStruct(int size)
{
	employee* arr = malloc(sizeof(employee) * size);
	if(!arr) return NULL;

		for (int i = 0; i < size; i++)
			{
				printf("Employee #%i name: ", i+1);
				scanf("%9s", arr[i].name);
				printf("Employee #%i age: ", i+1);
				scanf("%f", &arr[i].age);
				printf("Employee #%i id: ", i+1);
				scanf("%i", &arr[i].id);
			}
		return arr;
}

void passArrayStruct(employee** ptr, int size)
{
	*ptr = malloc(sizeof(employee) * size);
	if(!ptr)  exit(1);

	for (int i = 0; i < size; i++)
	{
		printf("Employee #%i name: ", i+1);
		scanf("%9s", (*ptr)[i].name);
		printf("Employee #%i age: ", i+1);
		scanf("%f", &(*ptr)[i].age);
		printf("Employee #%i id: ", i+1);
		scanf("%i", &(*ptr)[i].id);
	}

}
