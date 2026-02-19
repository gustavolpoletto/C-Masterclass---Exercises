//function recieves 2 sequences of lowercase letters and its size
//retur 1 if all the letters of the second sequence appears at the first

#include <stdio.h>
#include <stdlib.h>

int AllLettersIncluded (char* str1, const int size1, char* str2, const int size2);

int main ()
{
    const int size1 = 3;
    char arr1[size1] = {'d' , 'o' , 'g'};

    const int size2 = 4;
    char arr2[size2] = {'g' , 'o' , 'o' , 'd'};

    if (AllLettersIncluded(arr1, size1, arr2, size2))
    {
        printf("All letters included\n");
        return 0;
    }

    printf("Not all letters included\n");
    return 0;

}

int AllLettersIncluded (char* str1, const int size1, char* str2, const int size2)
{
    // crate an arr to count letters and repetitions to string 1
    int* ptr = calloc(26 , sizeof(int));
    if (ptr == NULL)
    {
        printf("error to alloc array");
        exit(0);
    }

    //build count array 1
    for(int i = 0; i < size1; i++)
    {
        ptr[str1[i] - 'a']++;
    }

    //verifies if all the letter in string 2 is in string 1
    for(int j = 0; j < size2; j++)
    {
        if (ptr[str2[j] - 'a'] == 0)
        {
            free(ptr);
            return 0;
        }
    }

    //if all the letters was a the first array
    free(ptr);
    return 1;
}
