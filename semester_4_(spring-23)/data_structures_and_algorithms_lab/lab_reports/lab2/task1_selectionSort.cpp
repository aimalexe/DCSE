/*
Task 1:
Implement Selection Sort and analyze its worst, best and average case complexity.
*/

#include <iostream>
using namespace std;

void displayArray(int* arr, int &ofLength){
    for(int i = 0; i < ofLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void swapBoth(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int* selectionSort(int arr[], int &arrLength){
    for(int step = 0, min,i; step < arrLength; step++){
        min = step;
        for (i = step + 1; i < arrLength; i++)
            if(arr[min] > arr[i])
                min = i;
        swapBoth(arr[min], arr[step]);
    }
    return arr;
}

int main(){
    int arrSize = 10;
    int arr[arrSize] = {5, 1, 4, 2, 8, 7 ,9, 10, 87, -3};

    cout<<"Unsorted Array: "<<endl;
    displayArray(arr, arrSize);

    int *sortedArr = selectionSort(arr, arrSize);

    cout<<"Sorted Array: "<<endl;
    displayArray(sortedArr, arrSize);

    return 0;
}

