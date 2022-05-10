#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include<sys/types.h>

// 파일 권한 변경                          argv[0]  argv[1]      argv[2]
int main(int argc, char **argv) {    // ./ex02    0777(권한)  aa(파일명)
    int perm = strtol(argv[1],(char**)NULL, 8);
    chmod(argv[2],perm);
}
