#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

/*
    A function which reads from an opened source file and write/append to opened destination file.

        @param sourceFileDescriptor : pointer to source file descriptor.
        @param destinationFileDescriptor : pointer to destination file descriptor.

        @return -1 : When unsuccessful, 
        @return 0 : When successful
*/
int readWriteOnly(const int *sourceFileDescriptor, const int *destinationFileDescriptor)
{
    char buffer[10];
    int readSrc, write2Dist;
    while (1)
    {
        readSrc = read(*sourceFileDescriptor, buffer, 10);
        if (readSrc == -1)
        {
            fprintf(stderr, "Something went wrong while reading from the src file: %d due to %s\n", *sourceFileDescriptor, strerror(errno));
            return -1;
        }

        write2Dist = write(*destinationFileDescriptor, buffer, readSrc);
        if (write2Dist == -1)
        {
            fprintf(stderr, "Something went wrong while writing to the destination file: %d due to %s\n", *sourceFileDescriptor, strerror(errno));
            return -1;
        }

        if (readSrc == 0)
            break;
    }

    return 0;
}

/*
    A function which open a source file for reading and destination file for writing / appending. If destination file is not present it create it. After the operation is done it closes the files too.

        @param source : pointer to source file path/name
        @param destination : pointer to destination file path/name

        @return -1 : When unsuccessful
        @return 0 : When successful
*/
int readWrite(const char *source, const char *destination)
{

    // 1. open sourc file (for reading only)
    int srcFile = open(source, O_RDONLY);
    if (srcFile == -1)
    {
        fprintf(stderr, "Something went wrong while opening the source file: %s due to %s\n", source, strerror(errno));
        return -1;
    }

    // 2. open destination file if not present create it (for writing only)
    int destFile = open(destination, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU | S_IRWXG | S_IRWXO);
    if (destFile == -1)
    {
        fprintf(stderr, "Something went wrong while opening the destination file: %s due to %s\n", destination, strerror(errno));
        return -1;
    }

    // 3. Read from src file
    // 4. write to destination from src file
    if(readWriteOnly(&srcFile, &destFile) == -1) return -1;

    // 5. Close destination and src files
    int closeSrc = close(srcFile);
    int closeDest = close(destFile);
    if (closeSrc == -1 || closeDest == -1)
    {
        fprintf(stderr, "Error while closing the file. %s\n", strerror(errno));
        return -1;
    }

    return 0;
}
