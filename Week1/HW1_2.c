/*국제경영학과 4학년 20190466 김미현*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int x) {
	int i, flag = 1;

	for (i = 2; i < x; i++) {
		if (x % i == 0)
			flag = 0;
	}
	return flag;
}
int main(void) {
	int i;


	for (i = 2; i <= 30; i++) {
		if (isPrime(i) == 1)
			printf("%d ", i);
	}
	printf("\n");
}