#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Stdlib.h>
int main(void){
    int n;
    int* arr;

    scanf("%d", &n);

    arr = (int*)malloc(sizeof(int)*n);

    if(!arr){
        printf("메모리를 할당할 수 없습니다.");
        return 0;
    }

    //arr에 값 입력
    
    free(arr);
}