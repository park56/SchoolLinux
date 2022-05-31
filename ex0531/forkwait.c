#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>



int main(){
    int pid, status, child;

    pid = fork();

    printf("처음 프로세스 pid = %d",getpid());
    if(pid == 0){
        //자식프로새스 
        printf("자식프로세스 pid = %d",getpid());
        exit(1);
    }
    child = wait(&status);
    printf("부모 프로세스 pid = %d child = %d\n",getpid(), child);
}