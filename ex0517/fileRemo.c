#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv){
    if(argc == 2){
        printf("삭제하실 디렉토리명 입력하세요\n");
        return -1;
    }

    if(rmdir(argv[1]))
}