#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("myfile",O_RDWR);

	if(fd == -1){
		printf("file open fail\n");
	}
	else{
		printf("To success file\n");
	}

	return 0;
}
