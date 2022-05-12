#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
get_cycle_number(int n) {
	if (n == 1) {
	printf("%d ", n);
	return 1;
	}

	if (n % 2 == 0) {
		printf("%d ", n);
		get_cycle_number(n / 2) * 2;
		
	}
	else if (n % 2 == 1) {
		printf("%d ", n);
		get_cycle_number(n * 3 + 1) * 3 + 1;
		
	}
}
int main(void) {
	int num;

	scanf("%d", &num);

	get_cycle_number(num);
	printf("\n");

	return 0;
}
