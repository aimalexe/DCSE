#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int ROWS = 5;
const int COLUMNS = 10;

void displayArray(int arr[][COLUMNS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void initArray(int arr[][COLUMNS]){
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLUMNS; j++)
            arr[i][j] = 10 + rand() % 90;
}

void swapBoth(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int first, int last){
    int pivot = arr[first];
    int lwr = first + 1;
    int upr = last;

    bool done = false;
    while(!done){
        while(lwr <= upr && arr[lwr] <= pivot)
            lwr++;
        
        while(lwr <= upr && arr[upr] >= pivot)
            upr--;

        if(upr < lwr)
            done = true;
        else
            swapBoth(&arr[lwr], &arr[upr]);
    }
    swapBoth(&arr[first], &arr[upr]);

    return upr;
}

void quickSort(int *arr, int left, int right) {
    if (left < right){
        int pivot = partition(arr, left, right);

        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

//? TODO: Implement QuickSort for 2d array!!!

int main(){
    int arr[ROWS][COLUMNS];
    int* arrPtr = &arr[0][0];
    initArray(arr);

    printf("Unsorted 2D-Array: \n");
    displayArray(arr);

    quickSort(arrPtr, 0 , ROWS*COLUMNS - 1);
    printf("Sorted 2D-Array: \n");
    displayArray(arr);

    return 0;
}