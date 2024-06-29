#include <iostream>
#include <cstdlib>
#include <ctime>
#include <pthread.h>
using namespace std;

#define SEQUENCE_LENGTH 1000000000
#define NUM_THREADS 4

char dnaSequence[SEQUENCE_LENGTH];
int results[NUM_THREADS];

void *SequenceThread(void *arg)
{
    int threadID = *(int *)arg;
    // divided total sequence by number of threads to get segmentsize
    int segmentSize = SEQUENCE_LENGTH / NUM_THREADS; 

    int start = threadID * segmentSize; 
    int end = (threadID + 1) * segmentSize;
    int count = 0;

    for (int i = start; i < end; i++)
    {
        if (dnaSequence[i] == 'A')
        {
            count++;
        }
    } 
    results[threadID] = count;
    pthread_exit(NULL);
}

int SequenceSequential()
{
    int count = 0;

    for (int i = 0; i < SEQUENCE_LENGTH; i++)
    {
        // we perform analysis on DNA sequence
        if (dnaSequence[i] == 'A')
        {
            count++;
        }
    }

    return count;
}

int main()
{
    srand(time(NULL));

    // here we generate random DNA sequence
    for (int i = 0; i < SEQUENCE_LENGTH; i++)
    {
        int randomNum = rand() % 4;
        switch (randomNum)
        {
        case 0:
            dnaSequence[i] = 'A';
            break;
        case 1:
            dnaSequence[i] = 'T';
            break;
        case 2:
            dnaSequence[i] = 'C';
            break;
        case 3:
            dnaSequence[i] = 'G';
            break;
        }
    }

    // threaded execution
    clock_t startThread = clock();

    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
    {
        threadIDs[i] = i;
        pthread_create(&threads[i], NULL, SequenceThread, &threadIDs[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    { // waiting for threads to complete
        pthread_join(threads[i], NULL);
    }

    int totalThread = 0;
    for (int i = 0; i < NUM_THREADS; i++)
    {
        totalThread = totalThread + results[i];
    }

    clock_t endThread = clock();
    double timeTakenThreaded = double(endThread - startThread) / CLOCKS_PER_SEC;

    // sequential execution starts here
    clock_t startSequential = clock();

    int totalSequential = SequenceSequential();

    clock_t endSequential = clock();
    double timeTakenSequential = double(endSequential - startSequential) / CLOCKS_PER_SEC;

    cout << "Total occurrences of 'A' in the DNA sequence (Threaded): " << totalThread << endl;
    cout << "Time taken (Threaded): " << timeTakenThreaded << " seconds" << endl;

    cout << "Total occurrences of 'A' in the DNA sequence (Sequential): " << totalSequential << endl;
    cout << "Time taken (Sequential): " << timeTakenSequential << " seconds" << endl;

    return 0;
}