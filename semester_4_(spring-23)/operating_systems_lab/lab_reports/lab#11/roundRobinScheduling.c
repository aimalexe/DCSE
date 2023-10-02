#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

const int ROWS = 5;
const int COLUMNS = 7;
const int TIME_QUANTUM = 5;
int CURRENT_TIME = 0;

#define PID 0 // process id
#define AT 1  // Arrival time
#define BT 2  // Burst time
#define ST 3  // Start time
#define ET 4  // End time
#define WT 5  // Wait time
#define TAT 6 // Turn around time

// Display the array
void displayArray(int arr[][COLUMNS])
{
    printf("|----|----|----|----|---|----|----|\n");
    printf("|PID |AT  |BT  |ST  |ET |WT  |TAT |\n");
    printf("|----|----|----|----|---|----|----|\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
            j == COLUMNS - 1 ? printf("| %d |", arr[i][j]) : printf("| %d ", arr[i][j]);
        printf("\n");
    }
    printf("|----|----|----|----|---|----|----|\n");
}

// Suppose all processes arrive at same time.
void initATtoZero(int arr[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMNS; j++)
        {
            if (j == PID)
                arr[i][j] = i + j + 1;
            else if (j == BT)
                arr[i][j] = 10 + rand() % 50;
            else
                arr[i][j] = 0;
        }
}

void initArray(int arr[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMNS; j++)
        {
            if (j < 3)
                arr[i][j] = 10 + rand() % 90;
            else
                arr[i][j] = 0;
        }
}

// Assigning CPU to each proccess for a quantum of time.
void assignCPU(int processes[][COLUMNS], int chart[])
{
    for (int i = 0; i < ROWS; i++)
        if (processes[i][BT] != 0)
        {
            processes[i][BT] -= TIME_QUANTUM;        // Assigning cpu to a proccess
            chart[CURRENT_TIME] = processes[i][PID]; // Adding it to gant chart
            CURRENT_TIME++;
            if (processes[i][BT] < 0)
                processes[i][BT] = 0;
                processes[i][ET] = CURRENT_TIME * TIME_QUANTUM;
                processes[i][WT] = processes[i][ET] - processes[i][BT] - processes[i][AT];
                processes[i][TAT] = processes[i][ET] - processes[i][AT];
        }

    for (int i = 0; i < ROWS; i++)
    {
        if (processes[i][BT] != 0)
            assignCPU(processes, chart);
        else
            return;
    }
}

void displayGanttChart(int *chart, int length)
{   
    printf("Gant Chart:\t|");
    for (int i = 0; i < length; i++)
    {
        printf("P%d\t|", chart[i]);
    }
    printf("\n");
}

void calculateStartTime(int arr[][COLUMNS])
{   
    arr[0][ST] = 0;
    for(int i = 1; i < ROWS; i++)
        arr[i][ST] = arr[i-1][ST] + TIME_QUANTUM;
}

int main()
{
    int processes[ROWS][COLUMNS];
    int total_time = 0;
    initATtoZero(processes);
    displayArray(processes);
    for (int i = 0; i < ROWS; i++)
        total_time += processes[i][BT];

    int chartSize = total_time % 5 == 0? total_time/TIME_QUANTUM :  total_time/TIME_QUANTUM + 1; // ? I dont Know of 2 but is added for correcting output.
    printf("%d, %d\n", total_time, chartSize);
    int gantChart[chartSize];
    assignCPU(processes, gantChart);
    calculateStartTime(processes);
    displayArray(processes);
    displayGanttChart(gantChart, chartSize);
    return 0;
}

// TODO: Calculate Wait Time and also simplify by nesting functions