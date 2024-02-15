// Implement the mov command.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include "../../reusable_code_snippets/readWrite.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s SOURCE DESTINATION.\n", argv[0]);
        return 1;
    }

    if (readWrite(argv[1], argv[2]) < 0)
    {
        perror("Something went wrong while reading or writing a file.\n");
        return 1;
    }

    // 6. delete the source file
    int removeSrc = unlink(argv[1]);
    if (removeSrc == -1)
    {
        fprintf(stderr, "Something went wrong while deleting the file: %s due to %s\n", argv[1], strerror(errno));
        return 1;
    }

    printf("Copied from SRC to DIST & SRC removed :)\n");

    return 0;
}