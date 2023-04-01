/*
Task 2:
Implement Bubble Sort and analyze its worst, best and average case complexity.
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
    for (int i = 0; i < arrSize; i++)            // c.n
        for(int j = 0; j < arrSize-1; j++)      //c.n * c.n
            if(arr[j] > arr[j + 1])             //c.n * c.n
                swapBoth(arr[j], arr[j + 1]);   //c.n * c.n

    return arr;                                 // c.1
    /*
        T(n) = c.n + (c.n)^2 + (c.n)^2 + (c.n)^2
            = c.n + 3(c.n)^2
            = n^2 + n
            = O(n^2)
    */
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
