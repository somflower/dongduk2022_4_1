/*�����濵�а� 4�г� 20190466 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void) {
	int scores[6], i;
	char answer;

	srand(time(NULL));

	 do{
		for (i = 0; i < 6; i++) {
			scores[i] = (rand() % 46);
		}

		printf("*** �ζ� ��ȣ ������ ***\n");

		printf("���� ��ȣ: ");
		for (i = 0; i < 6; i++) {
			printf("%d ", scores[i]);
		}

		printf("\n�ٽ� �����ϰڽ��ϱ�? (y/n): ");
		scanf("%c", &answer);
		
		while (getchar() != '\n')   //fflush(stdin)�� ���� ���, �Է¹��� ����
			continue;

	} while (answer != 'n');

	return 0;

}