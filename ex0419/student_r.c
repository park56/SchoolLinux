#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>, 만
#include <string.h>
#include <fcntl.h>

typedef struct{
    char name[24];
    int id;
    int score;
} STUDENT;

char c;

int main(){
    int fd1;
    STUDENT student;

    fd1 = open("studentDB", O_RDONLY);
    if (fd1 == 1){
        printf("file open fail");
    }
    do{
        printf("몇번쨰 학번을 검색 하시겠습니까? : ");
        scanf("%d",&student.id);        
        lseek(fd1,student.id * sizeof(student), SEEK_SET);

        if(read(fd1, &student,sizeof(student)) > 0 && student.id != 0){
            printf("학번%d 이름%s 점수%d",student.id, student.name,student.score);
        }

        printf("계속 하시겠습니까? (Y/N) : ");
        scanf("%c",&c); 
        getchar();
        printf("c = %c",c);
    }   while(c == 'Y');
}
