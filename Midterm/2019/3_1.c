#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int solution(int n){
	int i;

	for(i=0;n!=0;i++){
		n = n / 10;
	}
	return i;
}
int main(void) {
	int n;

	scanf("%d", &n);
	printf("%d\n", solution(n));

	return 0;
}
