#include<stdio.h>
#include <stdlib.h>

void atexit_handler(){
    printf("atexit_handler 함수를 실행합니다\n");
}

void atexit_handler2(){
    printf("atexit_handler2 함수를 실행합니다\n");
}

int main() {

    // atexit = exit이 일어나면 스택순으로 정리된 atexit이 실행됨 (코드 기준으로 역순) 
    // malloc 자원 해제 같은것에 사용됨

    atexit(atexit_handler);
    printf("중간에 끼여있음\n");
    atexit(atexit_handler2);

    printf("main함수 종료\n");
    exit(0);
}