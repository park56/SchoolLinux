#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

extern void ls(char *argc);

void makefile(){
    printf("파일 이름을 입력하세요  ex) ../myfile   : ");
    char fileName[20];
    scanf("%s",fileName);

    int fd1 = open(fileName, O_CREAT,0777);

    if(fd1 == -1){
        printf("%s파일을 생성하지 못했습니다. 다른 이름으로 다시 시도해주세요\n\n",fileName);
        return;
    }
    printf("%s파일을 생성했습니다\n\n",fileName);
    return;
}

void deletefile(){
    printf("파일 이름을 입력하세요  ex) ../myfile  : ");
    char fileName[20];
    scanf("%s",fileName);
    printf("fileName : %s\n",fileName);
 
    int rm = remove(fileName);

    if(rm == 0){
        printf("%s파일을 삭제했습니다\n\n",fileName);
        return;
    } 
        printf("%s파일을 삭제하지 못했습니다. 이름을 확인해 주세요\n\n",fileName);
    return;
}

void changeOwn(){

    char fileImpor[2][20];
    printf("파일 이름을 입력하세요 ex) ../myfile 0777 : ");

    scanf("%s",fileImpor[0]);
    scanf("%s",fileImpor[1]);

    int perm = strtol(fileImpor[1],(char**)NULL, 8);
    int chm = chmod(fileImpor[0],perm);

    if(chm == -1){
        printf("%s파일의 권한을 %s로 변환하지 못했습니다\n\n",fileImpor[0],fileImpor[1]);
        return;
    } 
    printf("%s파일의 권한을 %s로 변환했습니다\n\n",fileImpor[0],fileImpor[1]);
    return;
}

void readFIle(){
    char fileName[20];
    char buf[1024];
    int fg;
    printf("읽고 싶은 파일이름을 입력해주세요 : ");
    scanf("%s",fileName);

    fg = open(fileName,O_RDWR);
    if(fg == -1){
        printf("파일 열기 오류\n");
        return;
    }

    read(fg,buf,1024);
    puts(buf);

    return;
}

void modifiedFile(){
    
    char fileName[20];
    char writeBuf[2000] = {0};
    char tempWrite[500];

    int tempIndex;
    int fileOp;
    //int fr;
    FILE *fr;
    int isErr;

    printf("파일 이름을 입력하세요 : ");
    scanf("%s",fileName);


    printf("파일을 덮어씌울려면 1 내용을 추가하려면 2 : ");
    scanf("%d",&fileOp);

    if(fileOp == 1){
        //fr = open(fileName,O_TRUNC|O_RDWR,0777);
        fr = fopen(fileName,"w");
        if(fr < 0){
            printf("\n파일을 여는데 실패했습니다\n");
            return;
        }
        //lseek(fr,0,SEEK_SET);
    }else if(fileOp == 2){
        //fr = open(fileName,O_APPEND|O_RDWR,0777);
        fr = fopen(fileName,"a");
        if(fr < 0){
            printf("\n파일을 여는데 실패했습니다\n");
            return;
        }
        //lseek(fr,-2,SEEK_CUR);
    }else{
        printf("\n파일을 수정하는데 실패했습니다\n");
        return;    
    }

    printf("파일의 내용을 입력하세요 (나가려면 엔터 후 quit를 입력하세요)\n");
    
    while(1){
        scanf(" %[^\n]s",tempWrite);
        getchar();  
        
        if(strcmp(tempWrite,":quit") == 0){
            break;
        }

        strcat(writeBuf,tempWrite);

        isErr = fputs(writeBuf,fr);
        if(isErr == EOF){
            printf("\n파일 쓰기 에러");
            return;
        }
        isErr = fputs("\n",fr);
        if(isErr == EOF){
            printf("\n파일 쓰기 에러");
            return;
        }
        memset(tempWrite,0,sizeof(tempWrite));
        memset(writeBuf,0,sizeof(writeBuf));
    }

    //int isErr = write(fr,writeBuf,sizeof(writeBuf));
    fclose(fr);
    printf("\n파일 쓰기 성공 %d bytes",isErr);
    return;
}

void changeFileName(){
    
    char files[2][20];

    printf("파일/디렉토리명 입력 : ");
    scanf("%s",files[0]);

    printf("새 파일/디렉토리명 입력 : ");
    scanf("%s",files[1]);

   if ( rename(files[0], files[1]) != 0 ) {
        printf("파일/디렉토리명 변경 실패\n");
        return;
   }
     printf("%s를 %s로 변경\n",files[0],files[1]);
     return;
}

void makeDirectory(){

    char directoryName[20];
    printf("생성할 디렉토리명 입력 : ");
    scanf("%s",directoryName);

    if(mkdir(directoryName, 0777) == -1){
        printf("\n디렉토리 생성 실패\n");
        return;
    }

    printf("\n%s 디렉토리 생성\n",directoryName);
    return;
}

void removeDirectory(){

    char directoryName[20];
    
    printf("삭제할 디렉토리명 입력 : ");
    scanf("%s",directoryName);

    if(rmdir(directoryName) == 0 ){
        printf("\n%s디렉토리가 삭제되었습니다\n",directoryName);
        return;
    }
       printf("\n%s디렉토리를 삭제하지 못했습니다\n",directoryName);   
     return;
}

/* ls 부분 */
struct aa
{
    char name[512];
};

char type(mode_t mode)
{
    if (S_ISDIR(mode)){
        return 'd';
    }  else  return '-';
}

char *perm(mode_t mode)
{
    static char myString[10] = "----------"; 

    strcpy(myString, "---------");

    if (mode & (S_IREAD >> 1)){
        myString[0] = 'r';
    }
    if (mode & (S_IWRITE >> 1)){
        myString[1] = 'w';
    }
    if (mode & (S_IEXEC>>1)){
        myString[2] = 'x';
    }
    if (mode & (S_IREAD >> 3)){
        myString[3] = 'r';
    }
    if (mode & (S_IWRITE >> 3)){
        myString[4] = 'w';
    }
    if (mode & (S_IEXEC >> 3)){
        myString[5] = 'x';
    }
    if (mode & (S_IREAD >> 6)){
        myString[6] = 'r';
    }
    if (mode & (S_IWRITE >> 6)){
        myString[7] = 'w';
    }
    if (mode & (S_IEXEC >> 6)){
        myString[8] = 'x';
    }
    return myString;
}

void printStat(char *pathname, char *file, struct stat *st)
{
    printf("%c%s", type(st->st_mode), perm(st->st_mode));
    printf("%10ld\t", st->st_blocks);
    printf(" %3ld",st->st_nlink);
    printf(" %s %s",(getpwuid(st->st_uid))->pw_name,(getgrgid(st->st_gid))->gr_name);
    printf(" %10ld",st->st_size);
    printf(" %.12s",ctime(&st->st_mtime));
    printf(" %s\n",file);
}

void ls(char *argv)
{
    DIR *dp;

    struct dirent *d;
    char path[BUFSIZ];
    struct stat st;

    char directoryname[512];

    char tempPath[512] = "/home/p/LinuxClass/fileController";
    strcat(tempPath,argv);

    printf("%s\n\n",tempPath);
    //strcpy(directoryname, &argv[1]);
    strcpy(directoryname, tempPath);
    
    dp = opendir(directoryname);
    if (dp == NULL)
    {
        printf("존재하지 않는 경로\n");
        return;
    }
    while ((d = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", directoryname, d->d_name);
        if (lstat(path, &st) < 0){
            perror(path);
        }
        printStat(path, d->d_name, &st);
    }

    return;
} 



int main(void){

    int fileOption;

    while(fileOption != 0){
        
        printf("\n1: 파일생성 2: 파일삭제 3: 권한 수정  4: 파일 읽기 5: 파일내용 수정 6: 파일이름 수정 7: 디렉토리 생성 8: 디렉토리 삭제 9: ls 10: quit\n\n");
        printf("choose Option : ");
        
        scanf("%d",&fileOption);

        switch (fileOption)
        {
        case 1:
            makefile();
            break;
        case 2 :
            deletefile();
            break;
        case 3 : 
            changeOwn();
            break;
        case 4 :
            readFIle();
            break;
        case 5 :
            modifiedFile();
            break;
        case 6 :
            changeFileName();
            break;
        case 7 :
            makeDirectory();
            break;
        case 8 :
            removeDirectory();
            break;
         case 9 :
            printf("경로를 입력하세요. : ");
            char directoryName[20];
            scanf("%s",directoryName);
            ls(directoryName);
            break;
        case 10 :
            printf("프로그램을 종료합니다\n");
            return 0;
            break;
        default:
            printf("제대로 입력하세요");
            break;
        }
    }
}