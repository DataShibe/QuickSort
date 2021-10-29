#include <stdio.h>

#define arraySize 10

void quickSort(int*, int, int);
void printArray(int*);
void swap(int*, int, int);

int main()
{
    int array[arraySize] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    
    printf("Starting Array: ");
    printArray(array);

    quickSort(array, 0, arraySize - 1);
    
    printf("\nSorted Array: ");
    printArray(array);
    printf("\n");
}

void printArray(int* array) 
{
    for(int i = 0; i < arraySize; i++) printf("%d ", array[i]);   
}

void quickSort(int* array, int first, int last)
{
    int i = first;
    int j = last;
    int pivot = first;
    
    while(i < j)
    {
        while(array[i] <= array[pivot] && i < last) i++;
        while(array[j] > array[pivot]) j--;
        
        if(i < j) 
        {
            swap(array, i, j);
        }
        swap(array, j, pivot);
        
        quickSort(array, first, j - 1);
        quickSort(array, j + 1, last);
    }
}

void swap(int* array, int a, int b)
{
    int aVal = array[a];
    int bVal = array[b];
    
    array[b] = aVal;
    array[a] = bVal;
}
