/*
Write a program that reads numbers from the user in to an array of type “float”, average them and print the result.
Sample OUTPUT of the program
Enter length of the array: 5
Enter the elements of the array: 11	 22 	33 	44 	55
Average of the array:  33
Note: Add all the elements of array and divide by total number of elements. Use pointers.
*/

#include <iostream>
using namespace std;

int main(){
    int lengthOfArray;
    cout << "Enter length of the array? ";
    cin >> lengthOfArray;

    int arr[lengthOfArray];
    int sum = 0;

    cout << "Enter "<< lengthOfArray << "elements in array.\n";

    for(int i = 0; i < lengthOfArray; i++){
        cout<<"Enter a number in array at "<< i << ": ";
        cin >> arr[i];

        sum += arr[i];
    }

    int average = sum / lengthOfArray;

    cout << "The average is: "<< average;

    return 0;
}
