/*
Write a function that takes an int array and array’s size as argument and return maximum value of array elements.
Prototype of function:
int maxValue(int arr[], int Size)
Call to the function:
int ReturnedValue = maxValue (passArrayHere,passSizeHere)
Note:  Store first element of array in a temporary variable and then traverse the array and if you find
any value greater than temp update temp. After traversal return temp which contains the maximum value.
*/
#include <iostream>
using namespace std;

int maxValue(int arr[], int arrSize){
    int maxValue = arr[0];
    for(int i = 0; i < arrSize; i++)
        if(arr[i] > maxValue)
            maxValue = arr[i];
    return maxValue;
}

int main(){
    int lengthOfArray;
    cout << "Enter length of the array? ";
    cin >> lengthOfArray;

    int arr[lengthOfArray];

    cout << "Enter "<< lengthOfArray << "elements in array.\n";

    for(int i = 0; i < lengthOfArray; i++){
        cout<<"Enter a number in array at "<< i << ": ";
        cin >> arr[i];
    }

    int ReturnedValue = maxValue(arr, lengthOfArray);
    cout<< "\nThe max value is: " << ReturnedValue;
    return 0;
}
