#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(int n, int picked[], int m, int toPick) {
	//n=��ü ��, picked=�̾Ƽ� �����ϴ� �迭, m=�̾ƾ��ϴ� ��ü ����, toPick=m���߿��� ������ �̾ƾ��ϴ� ��
	int smallest; //������ ���� �� �߿� ���� ���� ��(���� �� �߿� ���� ū ��+1)
	int index; //���� �� �߿� ���� ū ���� ����ִ� index��ȣ
	int i;
	

	//�� ���� ���, base case, ���
	if (toPick == 0) {
		for (i = 0; i < m; i++)
			printf("%d  ", picked[i]);
		printf("\n");
		return;
	}

	//index����
	index = m - toPick - 1;

	//�������� ����(�����̶� ��ġ�� �ʱ� ����), ���� ���� �� ����
	if (m == toPick)
		smallest = 0; //ó�� �̴� ���
	else
		smallest = picked[index] + 1; //ó���� �ƴ� �̴� ���

	//�̱�
	for (i = smallest; i < n; i++) {
		picked[index + 1] = i;
		pick(n, picked, m, toPick - 1); //�ϳ��� �̾����Ƿ� toPick-1 �ؾ���
	}

}
int main(void) {
	int picked[4];
	
	pick(7, picked, 4, 4);

	return 0;
}
