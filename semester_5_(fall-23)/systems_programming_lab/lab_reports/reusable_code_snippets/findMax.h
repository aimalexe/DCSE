#include <stdlib.h>

/*
A function to return the maximum value in an array.

@param *array: a pointer to the array
@param *length: a pointer to length or size of the array

@return (int) the maximum number in an array
*/
int findMax(const int *array, const int *length)
{
    int max = array[0];
    for (int i = 1; i < *length; i++)
        if (max < array[i])
            max = array[i];
    return max;
}