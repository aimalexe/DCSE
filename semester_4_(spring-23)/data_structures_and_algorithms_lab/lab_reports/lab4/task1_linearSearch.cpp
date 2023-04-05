/*
Task 1:
Implement Linear Search and analyze its worst, best and average case complexity.
*/

#include <iostream>
using namespace std;

void displayArray(int* arr, int &ofLength){
    for(int i = 0; i < ofLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void displayResult(int index, int key){
    index > -1 ?
        cout<<"The key("<< key <<") is found at index: "<<index :
        cout<<"The key("<< key <<") is not present in given data!";
    cout << endl;
}

int linearSearch(int* data, int arrSize, int key){
    for(int index = 0; index < arrSize; index++)
        if(key == data[index]){
            displayResult(index, key);
            return index;
        }

    displayResult(-1, key);
    return -1;
}

int main(){
    int arrSize = 13;
    int arr[arrSize] = {87, 0, 5, 1, 4, 2, 8, -5 ,7 ,9, 10, 87, -3};

    cout<<"Data: "<<endl;
    displayArray(arr, arrSize);

    int returnedIndex1 = linearSearch(arr, arrSize, -5);
    int returnedIndex2 = linearSearch(arr, arrSize, 39);
    int returnedIndex3 = linearSearch(arr, arrSize, 9);
    int returnedIndex4 = linearSearch(arr, arrSize, 100);
    int returnedIndex5 = linearSearch(arr, arrSize, 87);

    return 0;
}