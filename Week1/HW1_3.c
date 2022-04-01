/*국제경영학과 4학년 20190466 김미현*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int total(int n) {
	int i, sum = 0;

	for (i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}
int main(void) {
	int n;
	
	do {
		printf("Input a number(-1 for exit): ");
		scanf("%d", &n);

		if(n != -1)
			printf("1부터 %d까지의 합은 %d\n", n, total(n));
	} while (n != -1);
}