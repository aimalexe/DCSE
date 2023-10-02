/*
Write a function that takes an int array and the array's size as arguments. It should create a new array
that is twice the size of the argument array. The function should copy the contents of the argument array
to the new array, and initialize the unused elements of new array with -1. The function should return a
pointer to the new array.
Note: Use malloc or new function from standard library for dynamic allocation of the array at runtime.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

int* resizeArray(int *arr, int sizeOfArr) {
    int* newArr = new int[sizeOfArr * 2];

    // Copy contents of old array to new array
    memcpy(newArr, arr, sizeOfArr * sizeof(int));
    for (int i = sizeOfArr; i < sizeOfArr * 2; i++) {
        newArr[i] = -1;
    }
    delete[] arr;
    return newArr;
}

int main() {
    int arr[3] = {1, 2, 3};
    int sizeOfArr = sizeof(arr) / sizeof(arr[0]);

    int* newArr = resizeArray(arr, sizeOfArr);

    for (int i = 0; i < sizeOfArr * 2; i++) {
        std::cout << newArr[i] << " ";
    }

    delete[] newArr;

    return 0;
}