/*
Task 1:
Implement Merge Sort and analyze its worst, best and average case complexity.
*/

#include <iostream>
using namespace std;

void displayArray(int* arr, int &ofLength){
    for(int i = 0; i < ofLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void mergeArray(int arr[], int left, int mid, int right){
    int l_index, r_index, arr_index = left;
    l_index = r_index = 0;

    int subLeftLength = mid - left + 1;
    int subRightLength = right - mid;

    int subLeft[subLeftLength];
    int subRight[subRightLength];

    for(; l_index < subLeftLength; l_index++)
        subLeft[l_index] = arr[left + l_index];

    for(; r_index < subRightLength; r_index++)
        subRight[r_index] = arr[mid + 1 + r_index];

    l_index = r_index = 0;

    while(l_index < subLeftLength && r_index < subRightLength){
        if(subLeft[l_index] < subRight[r_index])
            arr[arr_index++] = subLeft[l_index++];
            //arr_index++;
            //l_index++;
        else
            arr[arr_index++] = subRight[r_index++];
            //arr_index++;
            //r_index++;
    }

    while(l_index < subLeftLength)
        arr[arr_index++] = subLeft[l_index++];
        //arr_index++;
        //l_index++;

    while(r_index < subRightLength)
        arr[arr_index++] = subRight[r_index++];
        //arr_index++;
        //r_index++;
}

int* mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left ) / 2;

        mergeSort(arr, left, mid); //sorting left array
        mergeSort(arr, mid + 1, right); //sorting right array

        mergeArray(arr, left, mid, right); //merging arrays
    }
    return arr;
    /*
            T(n) = O(n log n):
                as we are recursively dividing array into sub arrays
                n = 2 ^ x
                x = log 2 n = log n
                for merging arrays again we use n comparison
                x = n * log n

            S(n) = O(n^2)

    */
}

int main(){
    int arrSize = 13;
    int arr[arrSize] = {87, 0, 5, 1, 4, 2, 8, -5,7 ,9, 10, 87, -3};

    cout<<"Unsorted Array: "<<endl;
    displayArray(arr, arrSize);

    int *sortedArr = mergeSort(arr, 0, arrSize - 1);

    cout<<"Sorted Array: "<<endl;
    displayArray(sortedArr, arrSize);

    return 0;
}