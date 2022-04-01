/*�����濵�а� 4�г� 20190466 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void input(char nameB[]) {
	printf("* Enter your name: ");
	scanf("%s", nameB/*, sizeof(nameB)*/);
}
void reverse(char nameC[]) {
	int i, cnt = 0;

	for (i = 0; nameC[i] != '\0'; i++)
		cnt++;

	printf("* Reverse: ");

	for (i = cnt - 1; i >= 0; i--)
		printf("%c", nameC[i]);
	printf("\n");
		
}
int main(void) {
	char nameA[100];
	int i;

	input(nameA);
	
	reverse(nameA);

}