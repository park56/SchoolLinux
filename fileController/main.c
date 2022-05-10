#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

void MakeFile(char frName) {
    int fd = open(frName, O_RDWR|O_CREAT|O_EXCL, 0777);
    if (fd < 0){
        perror("파일 크리에이트 오류");
    }
    close(fd);
    printf("파일 생성 성공");
    return 0;
}  

void MakeDirection(){

}

void DeleteFile() {

}  

void ReNameFile() {

}  

void ReadFile() {

}

void WriteFile() {

}

void ChModFile() {

}  




// 파일경로 /옵션 /파일 이름 
int main(void) {

    int fileOption;
    char fileRouteName;

    printf("1 : 파일만들기 2 : 파일삭제 3 : 파일읽기 4 : 파일쓰기 5 : 파일옵션 변경\n");
    scanf("%d",&fileOption);

    printf("파일경로 + 파일이름 입력 ex) ./myfile\n");
    scanf("%s",&fileRouteName);

    switch (fileOption){
    case 1:
        printf("makefile\n");
        MakeFile(fileRouteName);
        break;
    case 2:
        DeleteFile(fileRouteName);
        break;
    case 3:
        ReadFile(fileRouteName);
        break;
    case 4:
        WriteFile(fileRouteName);
        break;
    case 5:
        ChModFile(fileRouteName);
        break;
    default:
        printf("다시 입력하세요\n");
        break;
    }

    return 0;
}