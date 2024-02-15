#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void searchFile(const char *path, const char *target)
{
    struct stat entryStatistics;
    struct dirent *directoryEntry;
    DIR *dp;

    // open path(directory)
    if ((dp = opendir(path)) == NULL)
    {
        perror("Error while opening directory.\n");
        return;
    }

    // read the directory entries one by one
    while ((directoryEntry = readdir(dp)) != NULL)
    {
        char newPath[1024];

        // skip . and ..
        if ((!strcmp(directoryEntry->d_name, ".")) || (!strcmp(directoryEntry->d_name, "..")))
            continue;

        // S_ISDIR(entryStatistics.st_mode) ? printf("%s:\n", directoryEntry->d_name) : printf("%s\n", directoryEntry->d_name);
        // update the path by appending the file name with it.
        snprintf(newPath, sizeof(newPath), "%s/%s", path, directoryEntry->d_name);

        if (stat(newPath, &entryStatistics) == -1)
        {
            perror("Error while traversing statistics.\n");
            return;
        }

        if (S_ISDIR(entryStatistics.st_mode)) // if directory search for file in subdirectories.
            searchFile(newPath, target);
        else if (S_ISREG(entryStatistics.st_mode)) // if regular file compare the name of entry and target.
            if (!strcmp(target, directoryEntry->d_name))
                printf("%s/%s\n", path, directoryEntry->d_name);
    }

    if (closedir(dp) == -1)
    {
        perror("Error while opening directory.\n");
        return;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Need at exactly two arg. Usage:\n%s [DIR_PATH] [TARGET_FILE]\n", argv[0]);
        return 1;
    }

    searchFile(argv[1], argv[2]);

    return 0;
}