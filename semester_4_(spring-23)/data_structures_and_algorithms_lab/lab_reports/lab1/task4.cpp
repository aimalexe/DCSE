/*
Write a function that takes two int arrays and the arrays' sizes as arguments. It should create a new
array big enough to store both arrays. Then it should copy the contents of the first array to the new
array, and then copy the contents of the second array to the new array in the remaining elements, and
return a pointer to the new array.
Prototype:
int* mergeArray (int arrA[], int sizeA, int arrB[], int SizeB)
Note: You can also use pointer to hold an array argument. So the above function can be replaced by the
following function
Int * mergeArray(int* arrA, int sizeA, int* arrB, int sizeB)

*/
#include <iostream>
#include <cstdlib>
using namespace std;

int* mergeArray(int arrA[], int sizeA, int* arrB, int sizeB){
    int* newArr = new int[sizeA + sizeB ];
    int k = 0;

    for(int i = 0; i < sizeA; i++){
        newArr[k++] = arrA[i];
    }

    for(int i = 0; i <= sizeB; i++){
        newArr[k++] = arrB[i];
    }

    return newArr;
}

int main(){
    int arrA [4] = {1, 2, 3, 4};
    int arrB [5] = {4, 5, 6, 7, 8};

    int sizeA = sizeof(arrA) / sizeof(int);
    int sizeB = sizeof(arrB) / sizeof(arrB[0]);

    int *mergedArrays =  mergeArray(arrA, sizeA, arrB, sizeB);
    for (int i = 0; i < sizeA + sizeB; i++) {
        cout << mergedArrays[i] << " ";
    }
    return 0;
}
