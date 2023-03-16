/*
Write a program that takes the size of the array as input from the user, create the array and then take the elements
of array as input and sort in ascending order.
*/

#include <stdio.h>

void displayArray(int* arr, int ofLength){
    for(int i = 0; i < ofLength; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertArray(int* arr, int ofLength){
    printf("Enter %d Elements in array: \n", ofLength);
    for(int i = 0; i < ofLength; i++)
        scanf("%d", &arr[i]);
}

int* bubbleSort(int* arr, int arrSize){
    int temp;
    for (int i = 0; i < arrSize; i++)
        for(int j = 0; j < arrSize-1; j++)
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    return arr;
}

int main(void){
    int size;
    printf("Enter size of array? ");
    scanf("%d", &size);

    int arr[size];
    insertArray(arr, size);

    printf("\nYou entered this array: \n");
    displayArray(arr, size);

    int *sortedArray = bubbleSort(arr, size);
    printf("\nThe sorted array is: \n");
    displayArray(sortedArray, size);

    return 0;
}
