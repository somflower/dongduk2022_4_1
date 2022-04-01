/*국제경영학과 4학년 20190466 김미현*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void echo(int arrayB[]) {
	int i;

	for (i = 0; i < 5; i++) {
		scanf("%d", &arrayB[i]);
	}
	
}
void reverse(int arrayC[]) {
	int i;

	for (i = 4; i >= 0; i--) {
		printf("%d ", arrayC[i]);
	}
	printf("\n");
}
int main(void) {
	int arrayA[5], i;

	echo(arrayA);

	for (i = 0; i < 5; i++) {
		printf("%d ", arrayA[i]);
	}
	printf("\n");

	reverse(arrayA);
}