//  Program to calculate max in an array.

#include <stdio.h>
#include <stdlib.h>

int main(int argCount, char *argNames[])
{
    if(argCount < 3){
		fprintf(stderr, "Usage: %s number1 [number2 ...]\n", argNames[0]);
        return 1;
	}

    int max = atoi(argNames[1]);
    for (int i = 1; i < argCount; i++)
        if (max < atoi(argNames[i]))
            max = atoi(argNames[i]);
    return max;
}
