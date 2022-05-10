#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char **argv){

    // 인수로 오는 파일의 엔트리 보기   ex)  ./dir ../../LinuxClass

    // 디렉토리, 파일 엔트리셋 담김
    DIR *dp;
    // 디렉토리, 파일 담는곳
    struct dirent *d;
    // 폴더명
    char directoryname[512];
    
    if (argc == 1){
        strcpy(directoryname, ".");      // 현제파일
    }else{
        strcpy(directoryname, argv[1]);      // 입력파일
    }

    printf("directoryname = %s",directoryname);

    dp = opendir(directoryname);           // 이 파일을 열기(테이블 형식으로 담김)
    if (dp == NULL){
        perror("dp is null");
        exit(0);
    }
    while((d=readdir(dp)) !=NULL){
        printf("%s\n",d->d_name);
    }

    return 0;
}