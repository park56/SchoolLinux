#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include<sys/types.h>

int main(int argc, char **argv){     // argv에는 ./ex01 + 등등 이 넘어옴 
    printf("argc = %d\n",argc);

    printf("argv[0] = %s\n",argv[0]);
    printf("argv[1] = %s\n",argv[1]);

    struct stat buf;      // sys.stat 안에 있는 구조체
    lstat(argv[1],&buf);

    printf("stat %o %x\n",buf.st_mode,buf.st_mode);     // buf의 모드를 o와 x형으로 출력

    if ( S_ISREG(buf.st_mode))
        printf("일반 파일 입니다\n");
    if ( S_ISDIR(buf.st_mode))
        printf("디렉토리 파일 입니다\n");
    
}
