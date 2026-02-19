//Sort an array (arr) using function pointers to provide order

#include <stdio.h>
#include <stdbool.h>

bool ascending (int a, int b);
bool descending (int a, int b);
void sort(int* arr, int size, bool(* sortingOrder)(int,int));
void swap (int* a, int* b);

int main()
{
	int arr[] = {4, 2, 6, 1, 7, 6, 6, 19, 0};
	int size = sizeof(arr) / sizeof(int);

	int choice;
	do{
		printf("choose the order:\n[0]Ascending\n[1]Descending\n");
		scanf("%i", &choice);
	} while(choice != 0 && choice != 1);



	bool (*order[])(int, int) = {ascending , descending};

	sort(arr, size, order[choice]);

	for (int i = 0; i < size; i++)
		printf("%i ", arr[i]);
	printf("\n");
}


bool ascending (int a, int b)
{
	return a < b;
}

bool descending (int a, int b)
{
	return a > b;
}

void sort(int* arr, int size, bool(*sortingOrder)(int,int))
{
	for (int i = 0; i < size - 1; i++)
	{
		for( int j = 0; j < size - i - 1 ; j++)
		{
			if(!sortingOrder(arr[j], arr[j+1]))
				swap (&arr[j], &arr[j+1]);
		}
	}
}

void swap (int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
