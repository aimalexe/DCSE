/*
Task 1:
Probe peak element in one dimensional array and analyze its worst, best and average case 
complexity.
*/

#include <iostream>
using namespace std;

int findPeakElement(int *arr, int left, int right, int length){
    int mid = left + (right - left) / 2;

    if(
        (mid == 0 || arr[mid - 1] <= arr[mid] ) &&
        (mid == length - 1 || arr[mid] >= arr[mid + 1])
    )
        return mid;
    else if(mid > 0 && arr[mid] < arr[mid - 1])
        return findPeakElement(arr, left, mid - 1, length);
    else
        return findPeakElement(arr, mid + 1, right, length);
}


int main(){
    int arrSize = 13;
    int arr[arrSize] = {87, 0, 5, 1, 4, 2, 8, -5 ,7 ,9, 10, 87, -3};

    int peak = findPeakElement(arr, 0, arrSize - 1, arrSize);
    cout<<peak<<": "<<arr[peak]<<endl;

    return 0;
}