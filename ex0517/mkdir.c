/* make file */

#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
    
    char di_name[20];
    if (argc != 2)
        strcpy(di_name, "temp");
    else
        strcpy(di_name, argv[1]);
    

    printf("di_name = %s\n",di_name);

    if(mkdir(di_name, 0777) == -1){
        perror("만들기 실패");
        return 1;
    }
    
    return 0;
}