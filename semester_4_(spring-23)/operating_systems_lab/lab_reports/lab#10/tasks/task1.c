// WRITE A C PROGRAM FOR CPU SCHEDULING ALGORITHM FOR FCFS:

#include <stdio.h>
#include <stdlib.h>

const int rows = 4; // no of rows
const int columns = 7;  // no of columns

#define PID 0 // process id
#define AT 1  // Arrival time
#define BT 2  // Burst time
#define ST 3  // Start time
#define ET 4  // End time
#define WT 5  // Wait time
#define TAT 6 // Turn around time

void swapRows(int arr[][columns], int row1, int row2)
{
    int temp;
    for (int c = 0; c < columns; c++)
    {
        temp = arr[row1][c];
        arr[row1][c] = arr[row2][c];
        arr[row2][c] = temp;
    }
}

// Sorting the array column wise with column no
void sortColumn(int arr[][columns], int columnNo)
{
    for (int r = 0; r < rows - 1; r++)                   // loop for rows
        for (int j = r; j >= 0; j--)                     // loop for comparisons
            if (arr[j][columnNo] > arr[j + 1][columnNo]) // Comparing rows of same col
                swapRows(arr, j, j + 1);                 // Swap row 1 and row 2
}

// Display the array
void display(int arr[][columns])
{
    printf("|---|---|---|---|---|---|---|\n");
    printf("|PID|AT |BT |ST |ET |WT |TAT|\n");
    printf("|---|---|---|---|---|---|---|\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            j == columns - 1 ? printf("| %d |", arr[i][j]) : printf("| %d ", arr[i][j]);
        printf("\n");
    }
    printf("|---|---|---|---|---|---|---|\n");
}

void calculate(int arr[][columns])
{
    // First Process
    arr[0][ST] = 0;
    arr[0][ET] = arr[0][ST] + arr[0][BT];
    arr[0][WT] = 0;
    arr[0][TAT] = arr[0][WT] + arr[0][BT];

    //  Processes > 1
    for (int i = 1; i < rows; i++)
    {
        arr[i][ST] = arr[i-1][ET];  // Previous process ending time
        arr[i][ET] =  arr[i][AT] + arr[i][BT];  // Ending time = Arrival time + Burst time
        arr[i][WT] = arr[i-1][WT] + arr[i][ST] - arr[i][AT];  // Waiting time = Starting time - Arrival time
        arr[i][TAT] =  arr[i][WT] + arr[i][BT]; // Turn around time = Waiting time + Burst time
    }
}

int main()
{
    int arr[rows][columns];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
        {
            if (j < 3)
                arr[i][j] = rand() % 10;
            else
                arr[i][j] = 0;
        }

    printf("Processes Data:\n");
    display(arr);
    printf("\nSorted column wise (AT):\n");
    sortColumn(arr, AT);
    display(arr);
    printf("\nComplete Table:\n");
    calculate(arr);
    display(arr);

    return 0;
}