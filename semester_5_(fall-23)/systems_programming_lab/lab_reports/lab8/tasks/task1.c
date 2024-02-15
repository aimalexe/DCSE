
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

int displayFileStatistics(struct dirent *directoryEntry)
{
    struct stat entryStatistics;
    struct group *g;
    struct passwd *p;
    char *ctime_no_newline;

    if (stat(directoryEntry->d_name, &entryStatistics) == -1)
    {
        perror("Error in statistics of the directory contents.\n");
        return -1;
    }

    if (!strcmp(directoryEntry->d_name, ".") || !strcmp(directoryEntry->d_name, ".."))
        return 0;

    printf("\t");
    // print if entry is a directory or a file
    S_ISDIR(entryStatistics.st_mode) ? printf("d ") : printf("- ");

    // printing permissions by taking bitwise and of permission bit with mode.
    S_IRUSR & entryStatistics.st_mode ? printf("r") : printf("-");
    S_IWUSR & entryStatistics.st_mode ? printf("w") : printf("-");
    S_IXUSR & entryStatistics.st_mode ? printf("x") : printf("-");
    S_IRGRP & entryStatistics.st_mode ? printf("r") : printf("-");
    S_IWGRP & entryStatistics.st_mode ? printf("w") : printf("-");
    S_IXGRP & entryStatistics.st_mode ? printf("x") : printf("-");
    S_IROTH & entryStatistics.st_mode ? printf("r") : printf("-");
    S_IWOTH & entryStatistics.st_mode ? printf("w") : printf("-");
    S_IXOTH & entryStatistics.st_mode ? printf("x") : printf("-");

    // No of links pointing to file or directory
    printf(" %ld", entryStatistics.st_nlink);

    // User Name from uid
    p = getpwuid(entryStatistics.st_uid);
    printf(" %s", p->pw_name);

    // Group Name from gid
    g = getgrgid(entryStatistics.st_gid);
    printf(" %s", g->gr_name);

    // Time and date of last access
    ctime_no_newline = strtok(ctime(&entryStatistics.st_ctime), "\n");
    printf(" %s", ctime_no_newline);

    // Entry name
    printf(" %s\n", directoryEntry->d_name);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc > 3)
    {
        fprintf(stderr, "Need at most three args. Usage:\n%s [OPTIONAL] [-l | FILE_NAME]\n", argv[0]);
        return 1;
    }

    DIR *thisDirectory = opendir(".");
    struct dirent *directoryEntries;

    // ls
    if (argc == 1)
    {
        printf("Directory Content:\n");
        while ((directoryEntries = readdir(thisDirectory)) != NULL)
        {
            if (!strcmp(directoryEntries->d_name, ".") || !strcmp(directoryEntries->d_name, ".."))
                continue;
            printf("\t%s\n", directoryEntries->d_name);
        }
    }

    // ls -l
    else if ((argc == 2) && (!strcmp(argv[1], "-l")))
    {
        printf("Directory Content Statistics:\n");
        while ((directoryEntries = readdir(thisDirectory)) != NULL)
            if (displayFileStatistics(directoryEntries) == -1)
                return 1;
    }

    // ls file.xyz
    else if (argc == 2)
    {
        while ((directoryEntries = readdir(thisDirectory)) != NULL)
            if (!strcmp(directoryEntries->d_name, argv[1]))
            {
                printf("File Found:\n\t%s\n", directoryEntries->d_name);
                break;
            }
    }

    // ls -l file.xyz
    else if ((argc == 3) && (!strcmp(argv[1], "-l")))
    {
        while ((directoryEntries = readdir(thisDirectory)) != NULL)
            if (!strcmp(argv[2], directoryEntries->d_name))
            {
                printf("File Found. Statistics:\n");
                if (displayFileStatistics(directoryEntries) == -1)
                    return 1;
                break;
            }
    }

    return 0;
}