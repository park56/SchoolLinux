#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include"header.h"

struct aa
{
    char name[512];
};

char type(mode_t mode)
{
    if (S_ISREG(mode))  return '-';
    if (S_ISDIR(mode))  return 'd';
}

char *perm(mode_t mode)
{
    static char myString[9] = "---------"; 

    strcpy(myString, "---------");

    if (mode & (S_IREAD >> 1)){
        myString[0] = 'r';
    }
    if (mode & (S_IWRITE >> 1)){
        myString[1] = 'w';
    }
    if (mode & (S_IEXEC>>1)){
        myString[2] = 'x';
    }
    if (mode & (S_IREAD >> 3)){
        myString[3] = 'r';
    }
    if (mode & (S_IWRITE >> 3)){
        myString[4] = 'w';
    }
    if (mode & (S_IEXEC >> 3)){
        myString[5] = 'x';
    }
    if (mode & (S_IREAD >> 6)){
        myString[6] = 'r';
    }
    if (mode & (S_IWRITE >> 6)){
        myString[7] = 'w';
    }
    if (mode & (S_IEXEC >> 6)){
        myString[8] = 'x';
    }
    return myString;
}

void printStat(char *pathname, char *file, struct stat *st)
{
    printf("%c%s ", type(st->st_mode), perm(st->st_mode));
    printf(" %ld\t", st->st_blocks);
    printf(" %3ld",st->st_nlink);
    printf(" %s %s",(getpwuid(st->st_uid))->pw_name,(getgrgid(st->st_gid))->gr_name);
    printf(" %9ld",st->st_size);
    printf(" %.12s",ctime(&st->st_mtime));
    printf(" %s\n",file);
}

void ls(char *argv)
{
    DIR *dp;

    struct dirent *d;
    char path[BUFSIZ];
    struct stat st;


    char directoryname[512];
    if (argc == 1)
    {
        strcpy(directoryname, ".");
    }
    else
    {
        strcpy(directoryname, argv[1]);
    }

    dp = opendir(directoryname);
    if (dp == NULL)
    {
        perror("dp is null");
        exit(0);
    }
    while ((d = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", directoryname, d->d_name);
        if (lstat(path, &st) < 0){
            perror(path);
        }

        printStat(path, d->d_name, &st);
    }

    return;
} 