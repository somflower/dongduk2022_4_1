/*국제경영학과 4학년 20190466 김미현*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int n, i, mul = 1;

	printf("Enter a number: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		mul *= 2;
	}
	printf("%d\n", mul);

}