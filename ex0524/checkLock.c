#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

void main() {
    int fd = open("aaa",O_RDWR);

    struct flock lock;

     /* 잠금 옵션 */
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;               
    lock.l_len = 100;
    
    fcntl(fd,F_GETLK,&lock);       //잠금검사    

    if(lock.l_type == F_WRLCK){
        printf("파일이 락걸려있음\n");
    }
    else if(lock.l_type == F_UNLCK){
        printf("파일이 풀려있음\n");
    }
    close(fd);
}
