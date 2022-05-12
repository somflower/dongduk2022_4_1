#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int h, w, s, i, j;
	char ladder[100][100] ={0,};

	//배열크기
	scanf("%d %d", &w, &h);

	//시작위치
	scanf("%d", &s);

	//사다리입력
	for (i = 0; i < h; i++) {
			scanf("%s", ladder[i]);
	}

	//서치
	for(i=0;i<h;i++){
		if(s == 0){
			if(ladder[i][s] == '1')
				s++;
		}
		else if(s == w-1){
			if(ladder[i][s-1] == '1')
				s--;
		}
		else{
			if(ladder[i][s] == '1')
				s++;
			else if(ladder[i][s-1] == '1')
				s--;
		}
	}

	printf("%d\n", s);

	return 0;
}