#include <stdio.h>

// QuickSort in C written by DataShibe at 29.10.2021

#define arraySize 10

void quickSort(int*, int, int);
void printArray(int*);
void swap(int*, int, int);

int main()
{
    // initializing the array
    int array[arraySize] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    
    printf("Starting Array: ");
    printArray(array);

    // calling quicksort with the arguments: array, most left index and most right index
    quickSort(array, 0, arraySize - 1);
    
    printf("\nSorted Array: ");
    printArray(array);
    printf("\n");
}

void printArray(int* array) 
{
    // looping through the elements in the array and printing them
    for(int i = 0; i < arraySize; i++) printf("%d ", array[i]);   
}

void quickSort(int* array, int first, int last)
{
    // i is the counter from the left to the right
    int i = first;

    // j is the counter from the right to the left
    int j = last;

    // pivot is set to the first element in the array
    int pivot = first;
    
    // while i is not crossing j:
    while(i < j)
    {
        // as long as the element at i is smaller than the pivot, increment i (move i to the right)
        while(array[i] <= array[pivot] && i < last) i++;

        // as long as the element at j is bigger than the pivot, decrement j (move j to the left)
        while(array[j] > array[pivot]) j--;
        
        // if i and j are crossing: 
        if(i < j) 
        {
            // swap i and j
            swap(array, i, j);
        }

        // swap the pivot with j, so the pivot isnt at the index one anymore
        swap(array, j, pivot);
        
        // call quicksort for the right side recursively
        quickSort(array, first, j - 1);

        // call quicksort for the left side recursively
        quickSort(array, j + 1, last);
    }
}

void swap(int* array, int a, int b)
{
    int aVal = array[a];
    int bVal = array[b];
    
    // swapping a and b in the array
    array[b] = aVal;
    array[a] = bVal;
}
