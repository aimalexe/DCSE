/*
Write a C++ program to find the position of a target value within a sorted array using binary
search
*/
#include <iostream>
using namespace std;

int binarySearchUsingLoop(int* arr, int arrSize, int key){
    int low = 0, high = arrSize - 1, mid;

    while (low <= high){
        mid = (low + high)/2;
        if(key < arr[mid])
            high = mid - 1;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binarySearchUsingRecursion(int *arr, int key, int low, int high){
    if(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return binarySearchUsingRecursion(arr, key, low, mid - 1);
        else
            return binarySearchUsingRecursion(arr, key, mid + 1, high);
    }
    return -1;
}

int main (){
    int arrSize = 9;
    int arr[arrSize] = {6, 12, 17, 23, 38, 45, 77, 84, 90};

    int searched1 = binarySearchUsingLoop(arr, arrSize, 90);
    if (searched1 == -1)
        cout << "Target not found." << endl;
    else
        cout << "Target found at index " << searched1 << "." << endl;

    int searched2 = binarySearchUsingRecursion(arr, 39, 0, arrSize-1);
    if (searched2 == -1)
        cout << "Target not found." << endl;
    else
        cout << "Target found at index " << searched2 << "." << endl;

    return 0;
}
