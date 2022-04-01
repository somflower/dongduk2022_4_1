/*�����濵�а� 4�г� 20190466 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void EnterArray(int array[]) {
	int i;

	for (i = 0; i < 5; i++) {
		scanf("%d", &array[i]);
	}
}
int CompareAB(int A[], int B[]) {
	int i;

	for (i = 0; i < 5; i++) {
		if (A[i] != B[i])
			return 0;
	}
	return 1;
}
int main(void) {
	int arrayA[5], arrayB[5];

	printf("Enter ù��° �迭: ");
	EnterArray(arrayA);

	printf("Enter �ι�° �迭: ");
	EnterArray(arrayB);

	if (CompareAB(arrayA, arrayB) == 1)
		printf("�� ���� �迭�� ����\n");
	else
		printf("�� ���� �迭�� �ٸ���\n");

}