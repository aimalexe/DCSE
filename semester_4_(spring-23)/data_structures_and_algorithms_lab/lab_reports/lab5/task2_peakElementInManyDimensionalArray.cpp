/*
Task 1:
Probe peak element in two dimensional array and analyze its worst, best and average case 
complexity.
*/

#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

int findPeak(int arr[ROWS][COLS], int rows, int cols, int mid) {
    int max_val = arr[0][mid];
    int max_row = 0;
    for (int i = 1; i < rows; i++) {
        if (arr[i][mid] > max_val) {
            max_val = arr[i][mid];
            max_row = i;
        }
    }
    if ((mid == 0 || arr[max_row][mid - 1] <= max_val) &&
        (mid == cols - 1 || arr[max_row][mid + 1] <= max_val)) {
        return max_val;
    }
    if (mid > 0 && arr[max_row][mid - 1] > max_val) {
        return findPeak(arr, rows, cols, mid - (mid / 2));
    }
    return findPeak(arr, rows, cols, mid + (mid / 2));
}

int main() {
    int arr[ROWS][COLS] = {{10, 8, 10},
                           {14, 15, 12},
                           {15, 9, 11}};
    int peak = findPeak(arr, ROWS, COLS, COLS/2);
    cout << "The peak value in the array is: " << peak << endl;
    return 0;
}
