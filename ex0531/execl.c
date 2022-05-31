#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
    printf("여기서 출력됨\n");
    if(fork() == 0){
        sleep(3);
        execl("/bin/echo","echo","hello",NULL);         // 이러면 덮어씌여져서 밑의 것들이 실행이 안됨
        printf("execl 실행 후 출력됨\n");
        exit(1);
    }
    printf("부모 프로세스 종료");
}