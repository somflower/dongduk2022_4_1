#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int comb (int n, int r){
	if (r == 0 || r == n)
		return 1;
	else
		return comb(n - 1, r - 1) + comb(n - 1, r);
		
}
int main(void) {
	int c10_5;

	c10_5 = comb(10, 5);

	printf("%d\n", c10_5);

	return 0;
}
