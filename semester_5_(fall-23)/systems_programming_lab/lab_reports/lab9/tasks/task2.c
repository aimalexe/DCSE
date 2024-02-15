#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// TODO Complete this function
void breadthFirstTraverse(char *path)
{
    struct stat entryStatistics;
    struct dirent *directoryEntry;
    DIR *dp;

    chdir(path);

    if ((dp = opendir(path)) == NULL)
    {
        perror("Error while opening directory.\n");
        return;
    }

    while ((directoryEntry = readdir(dp)) != NULL)
    {
        if ((!strcmp(directoryEntry->d_name, ".")) || (!strcmp(directoryEntry->d_name, "..")))
            continue;

        char newPath[1024];
        snprintf(newPath, sizeof(newPath), "%s/%s", path, directoryEntry->d_name);

        if (stat(newPath, &entryStatistics) == -1)
        {
            perror("Error while traversing statistics.\n");
            return;
        }

        if (S_ISDIR(entryStatistics.st_mode))
        {
            breadthFirstTraverse(newPath);
        }

    }

    closedir(dp);
}

int main(int argc, char *argv[])
{

    return 0;
}