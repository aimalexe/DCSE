#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * a function to close the file if error occur it prints the possible error.
 * @param fileDescriptor a file descriptor associated with an open file
 * @return void
*/
void closeFile(const int fileDescriptor)
{
    struct stat fileStat;
    char fileName[256];

    if (close(fileDescriptor) == -1)
    {
        // extract file name from its descriptor to print it with the message.
        if (fstat(fileDescriptor, &fileStat) == -1)
        {
            perror("Error in retrieving file statistics.\n");
            exit(1);
        }

        if (S_ISREG(fileStat.st_mode) && fileStat.st_dev != 0)
        {
            // Extract the file name from the device ID and inode number
            snprintf(fileName, sizeof(fileName), "/proc/self/fd/%d", fileDescriptor);

            // Read the symbolic link to get the file name
            ssize_t linkSize = readlink(fileName, fileName, sizeof(fileName) - 1);
            if (linkSize != -1)
                fileName[linkSize] = '\0';
            else
            {
                perror("Error reading symbolic link.\n");
                exit(1);
            }
        }
        else
            printf("The file associated with the descriptor is not a regular file.\n");

        fprintf(stderr, "Error closing output file\"%s\" due to %s", fileName, strerror(errno));
        exit(1);
    }
}