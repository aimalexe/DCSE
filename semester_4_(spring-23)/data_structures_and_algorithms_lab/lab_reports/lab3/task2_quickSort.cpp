/*
Task 2:
Implement Quick Sort and analyze its worst, best and average case complexity.
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

int partition(int *arr, int first, int last){
    int pivotValue = arr[first];

    int lower = first + 1;
    int upper = last;

    bool done = false;
    while(!done){
        while(lower <= upper && arr[lower] <= pivotValue )
            lower++;

        while(upper >= lower && arr[upper] >= pivotValue)
            upper--;

        if(upper < lower)
            done = true;
        else
            swapBoth(arr[lower], arr[upper]);
    }

    swapBoth(arr[first], arr[upper]);

    return upper;
}

int* quickSort(int arr[], int left, int right) {
    if (left < right){
        int pivot = partition(arr, left, right);

        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
    return arr;
}

int main(){
    int arrSize = 13;
    int arr[arrSize] = {87, 0, 5, 1, 4, 2, 8, -5,7 ,9, 10, 87, -3};

    cout<<"Unsorted Array: "<<endl;
    displayArray(arr, arrSize);

    int *sortedArr = quickSort(arr, 0, arrSize-1);

    cout<<"Sorted Array: "<<endl;
    displayArray(sortedArr, arrSize);

    return 0;
}