#include <unistd.h>

int main(){
    if(symlink("al", "alink") < 0){
        perror("에러");
    }
}