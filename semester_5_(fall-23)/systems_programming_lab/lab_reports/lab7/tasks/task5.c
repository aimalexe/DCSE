/* 
Task 5: Write a function that creates a delay of N seconds using select function. Pass 
N as an argument to the function
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/select.h>
#include <time.h>

int doDelay(int sec, int microSec)
{
    struct timeval t;
    t.tv_sec = sec;
    t.tv_usec = microSec;

    int ret = select(1, NULL, NULL, NULL, &t);
    
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <seconds> <micro_seconds>.\n", argv[0]);
        return 1;
    }

    printf("Starting program...\n");

    int ret = doDelay(atoi(argv[1]), atoi(argv[2]));

    printf("Continuing after the delay of sec: %d:%d.\n", atoi(argv[1]), atoi(argv[2]));
    return 0;
}
