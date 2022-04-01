/*국제경영학과 4학년 20190466 김미현*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void) {
	int scores[6], i;
	char answer;

	srand(time(NULL));

	 do{
		for (i = 0; i < 6; i++) {
			scores[i] = (rand() % 46);
		}

		printf("*** 로또 번호 생성기 ***\n");

		printf("생성 번호: ");
		for (i = 0; i < 6; i++) {
			printf("%d ", scores[i]);
		}

		printf("\n다시 생성하겠습니까? (y/n): ");
		scanf("%c", &answer);
		
		while (getchar() != '\n')   //fflush(stdin)과 같은 기능, 입력버퍼 삭제
			continue;

	} while (answer != 'n');

	return 0;

}