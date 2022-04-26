#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

typedef struct{
    char name[24];
    int id;
    int score;
} STUDENT;

int main(){
    int fd1 ;
    fd1 = open("studentDB",O_WRONLY|O_CREAT|O_TRUNC, 0640);
    if(fd1 == -1){
        printf("fd1 create 실패");
        return -1;
    }

    printf("학번 이름 점수 입력하세요\n");

    STUDENT student;

    while(scanf("%d %s %d",&student.id, &student.name, &student.score) == 3);  // 3개 입력했으면
    {
        lseek(fd1,student.id * sizeof(student), SEEK_SET);
        write(fd1, &student, sizeof(student));
    }   
    close(fd1);
}