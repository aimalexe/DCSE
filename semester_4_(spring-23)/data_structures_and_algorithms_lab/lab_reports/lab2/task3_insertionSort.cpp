/*
Task 3:
Implement Insertion Sort and analyze its worst, best and average case complexity.
*/

#include <iostream>
using namespace std;

void displayArray(int* arr, int &ofLength){
    for(int i = 0; i < ofLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int* insertionSort(int arr[], int &arrLength){
    for (int i =1, j, temp; i < arrLength; i++){    // c1.(n-1)
        temp = arr[i];                              // c1.(n-1)
        for(j = i; j > 0 && temp < arr[j-1]; j--)   // c1.(n-1) * c1.(n-1)
            arr[j] = arr[j - 1];                    //c1.(n-1) * c1.(n-1)
        arr[j] = temp;                              // c1.(n-1) * c1.(n-1)
    }
    return arr;                                     //c1.1
    /*
            T(n) = c1.(n-1) + c1.(n-1) + c1^2 * (n-1) * (n-1) + c1^2 * (n-1) * (n-1) + c1^2 *(n-1) * (n-1) + c1.1
                = 2c1.(n-1) + 3(n-1)(n-1)c1^2 + c1.1
                = n-1 + n^2 + n -2n + 1
                = n^2
                = O(n^2)
    */
}

int main(){
    int arrSize = 10;
    int arr[arrSize] = {5, 1, 4, 2, 8, 7 ,9, 10, 87, -3};

    cout<<"Unsorted Array: "<<endl;
    displayArray(arr, arrSize);

    int *sortedArr = insertionSort(arr, arrSize);

    cout<<"Sorted Array: "<<endl;
    displayArray(sortedArr, arrSize);

    return 0;
}
