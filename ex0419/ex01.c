#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(){
    // 파일에 변수 복사
    int fd1, fd2;

    fd1 = creat("myfile", 0600);

    char *str = "Hello Linux\n";
    write(fd1, str, strlen(str));     // fd1에 str, str의 길이

    fd2 = dup(fd1);  
    write(fd2, str, strlen(str));

    dup2(fd1, 1);    // 1 = stdin   0 = stdin
    write(fd1, str, strlen(str));

    printf("\nhello stdOut\n");   // myfile 안에 들어감
    return 1;
}
