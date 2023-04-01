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

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swapBoth(arr[i++], arr[j--]);
            //i++;
            //j--;
        }
    }

    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

int main(){
    int arrSize = 13;
    int arr[arrSize] = {87, 0, 5, 1, 4, 2, 8, -5,7 ,9, 10, 87, -3};

    cout<<"Unsorted Array: "<<endl;
    displayArray(arr, arrSize);

    quickSort(arr, 0, arrSize-1);

    cout<<"Sorted Array: "<<endl;
    displayArray(arr, arrSize);

    return 0;
}
