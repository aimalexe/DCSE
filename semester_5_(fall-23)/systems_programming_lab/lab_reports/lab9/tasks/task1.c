#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void depthFirstTraverse(const char *path, int depth)
{
    struct stat entryStatistics;
    struct dirent *directoryEntry;
    DIR *dp;

    if ((dp = opendir(path)) == NULL)
    {
        perror("Error while opening directory.\n");
        return;
    }

    while ((directoryEntry = readdir(dp)) != NULL)
    {
        char newPath[1024];

        if ((!strcmp(directoryEntry->d_name, ".")) || (!strcmp(directoryEntry->d_name, "..")))
            continue;

        for (int i = 0; i < depth; i++)
        {
            printf("   ");
        }

        S_ISDIR(entryStatistics.st_mode) ? printf("%s:\n", directoryEntry->d_name) : printf("%s\n", directoryEntry->d_name);
        snprintf(newPath, sizeof(newPath), "%s/%s", path, directoryEntry->d_name);

        if (stat(newPath, &entryStatistics) == -1)
        {
            perror("Error while traversing statistics.\n");
            return;
        }

        if (S_ISDIR(entryStatistics.st_mode))
        {
            depthFirstTraverse(newPath, depth + 1);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Need at exactly one arg. Usage:\n%s [DIR_PATH]\n", argv[0]);
        return 1;
    }

    printf("%s\n", argv[1]);
    depthFirstTraverse(argv[1], 1);

    return 0;
}