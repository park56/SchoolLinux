#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

// system = 자식프로세스를 자동으로 생성해서 실행해줌

int main(){
    int status1 = system("date");
    printf("종료 코드 %d\n", WEXITSTATUS(status1));
    
    sleep(3);
    int status2 = system("ps");
    printf("종료 코드 %d\n", WEXITSTATUS(status2));
    
    sleep(3);
    int status3 = system("ls");
    printf("종료 코드 %d\n", WEXITSTATUS(status3));
}