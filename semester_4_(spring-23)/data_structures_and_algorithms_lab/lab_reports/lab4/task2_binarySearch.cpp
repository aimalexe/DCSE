/*
Task 2:
Implement Binary Search and analyze its worst, best and average case complexity.
*/

#include <iostream>
using namespace std;

void displayArray(int* arr, int &ofLength){
    for(int i = 0; i < ofLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl << endl;
}

void displayResult(int index, int key){
    index > -1 ?
        cout<<"The key("<< key <<") is found at index: "<<index :
        cout<<"The key("<< key <<") is not present in given data!";
    cout << endl;
}

// Implementation of binary search through loops.
int loopingBinarySearch(int* data, int key, int dataSize){
    int left = 0, right = dataSize - 1, mid;
    
    while(left <= right){
        mid = left + (right - left)/2;

        if(data[mid] < key)
            left = mid + 1;
        else if(key < data[mid])
            right = mid - 1;
        else
            return mid;
    }

    return -1;
}

// Implementation of binary search through recursion.
int recurringBinarySearch(int* data, int key, int left, int right){
    if(left <= right){
        int mid = left + (right - left) / 2;

        if(data[mid] == key)
            return mid;
        else if (key < data[mid])
            return recurringBinarySearch(data, key, left, mid - 1);
            //moving right to mid - 1.
        else if( data[mid] < key)
            return recurringBinarySearch(data, key, mid + 1, right);
            //moving left to mid + 1.
    }
    return -1;
}

int main(){
    int arrSize = 13;
    int sortedArray[arrSize] = {-5, -3, 0, 1, 2, 4, 5, 7, 8, 9, 10, 87, 87};

    cout<<"Data: "<<endl;
    displayArray(sortedArray, arrSize);

    // Testing binary search implemented with loops
    int returnedIndex1 = loopingBinarySearch(sortedArray, -5, arrSize);
    displayResult(returnedIndex1, -5);

    int returnedIndex2 = loopingBinarySearch(sortedArray, 39, arrSize);
    displayResult(returnedIndex2, 39);

    int returnedIndex3 = loopingBinarySearch(sortedArray, 4, arrSize);
    displayResult(returnedIndex3, 4);

    // Testing binary search implemented with recursions.
    int returnedIndex4 = recurringBinarySearch(sortedArray, 100, 0, arrSize - 1);
    displayResult(returnedIndex4, 100);

    int returnedIndex5 = recurringBinarySearch(sortedArray, 87, 0, arrSize - 1);
    displayResult(returnedIndex5, 87);

    int returnedIndex6 = recurringBinarySearch(sortedArray, 9, 0, arrSize - 1);
    displayResult(returnedIndex6, 9);

    return 0;
}