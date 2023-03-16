/*
Q2:
Write a C++ program to sort a list of elements using the bubble sort algorithm.
Note: Bubble Sort works by swapping adjacent elements if they are in the wrong order.
*/
#include <iostream>
using namespace std;

void swapBoth(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void displayArray(int* arr, int &ofLength){
    for(int i = 0; i < ofLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int* bubbleSort(int* arr, int &arrSize){
    for (int i = 0; i < arrSize; i++)
        for(int j = 0; j < arrSize-1; j++)
            if(arr[j] > arr[j + 1])
                swapBoth(arr[j], arr[j + 1]);

    return arr;
}

int main(){
    int arrSize = 10;
    int arr[arrSize] = {5, 1, 4, 2, 8, 7 ,9, 10, 87, -3};

    cout<<"Unsorted Array: "<<endl;
    displayArray(arr, arrSize);

    int *sortedArr = bubbleSort(arr, arrSize);

    cout<<"Sorted Array: "<<endl;
    displayArray(sortedArr, arrSize);

    return 0;
}
//Aimal Khan.
