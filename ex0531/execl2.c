#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
    if(fork() == 0){
        printf("1번쨰 자식 프로세스 시작\n");
        sleep(1);
        execl("/bin/echo", "echo", "hi",NULL);
        printf("1번쨰 자식 프로세스 종료");
        exit(1);
    }

    if(fork() == 0){
        printf("2번쨰 자식 프로세스 시작\n");
        sleep(2);
        execl("/bin/date", "date",NULL);
        printf("2번쨰 자식 프로세스 종료");
        exit(1);
    }

    if(fork() == 0){
        printf("3번쨰 자식 프로세스 시작\n");
        sleep(3);
        execl("/bin/ls", "ls", "-al",NULL);
        printf("3번쨰 자식 프로세스 종료");
        exit(1);
    }
}