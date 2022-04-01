/*국제경영학과 4학년 20190466 김미현*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int scores[5], key, i;

	printf("Enter 5개의 정수: ");

	for (i = 0; i < 5; i++) {
		scanf("%d", &scores[i]);
	}

	printf("Enter a key: ");
	scanf("%d", &key);

	for (i = 0; i < 5; i++) {
		if (scores[i] == key)
			break;
	}

	if (i == 5)
		printf("없다\n");
	else
		printf("%d번째에 있다\n", i+1);
}