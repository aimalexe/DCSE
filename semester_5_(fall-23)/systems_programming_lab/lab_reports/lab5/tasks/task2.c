// Implement rm command.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s FILE_TO_DELETE.\n", argv[0]);
        return 1;
    }

    int deleteFile = unlink(argv[1]);
    if (deleteFile == -1)
    {
        fprintf(stderr, "Something went wrong while deleting the file: %s due to %s\n", argv[1], strerror(errno));
        return 1;
    }
    printf("Removed Successfully :)\n");

    return 0;
}