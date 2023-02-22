//Aimal Khan.

#include <iostream>
using namespace std;

int binarySearch(int searchIt, int *arr, int sizeOfArr){ //Find a number in set of given size.
    if(sizeOfArr == 0 || searchIt <= arr[0]) return -1;
    if(searchIt > arr[sizeOfArr-1]) return sizeOfArr;

    int mid, leftHalf = 0, rightHalf = sizeOfArr - 1;
    while(rightHalf - leftHalf > 1){
        mid = (leftHalf + rightHalf) / 2;
        (searchIt <= arr[mid] ? rightHalf : leftHalf) = mid;
    }
    return rightHalf;
}

int main(){
    int arrSize = 10;
    int arr[arrSize] = {1,2,3,4,5,6,7,8,9,10};

    int index = binarySearch(6, arr, arrSize);
    cout<<index;

    return 0;
}
