#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int changeInt(char *n, int digit)
{	
	//�Է¹��� n�� int������ �ٲ��ֱ�
	int i, N = 0;

	for (i = 0; i < digit; i++)
	{
		N = N * 10 + (n[i] - 48);
	}

	return N;
}
void changeK(char *arr, int N, int k, int Kdigit)
{
	int i;

	// k�� 1~9�� ���
	if (k > 1 && k < 10)
	{
		//�迭�� �Ųٷ� �ֱ�
		for (i = Kdigit - 1; i >= 0; i--)
		{
			// printf("arr[%d]: %c, N: %d\n", i, (N % k)+48, N);
			arr[i] = (N % k) + 48;
			N /= k;
		}
	}

	else if (k == 16)
	{
		//�迭�� �Ųٷ� ������ �������� 0~9���� Ȯ��
		for (i = Kdigit - 1; i >= 0; i--)
		{
			//�������� 0~9�̸� ���� ���� �ְ�
			if ((N % k) > 0 && (N % k) < 9)
			{
				arr[i] = (N % k) + 48;
				//printf("1������: %d \n",(N % k) + 48);
				N /= k;
			}
			else
			{
				arr[i] = (N % k) + 55;
				//printf("2������: %d \n",(N % k) + 55);
				N /= k;
			}
		}
	}

	//���ڿ� �迭�̴� �������� null�� �־��ֱ�
	arr[i] = '\0';
}
void calculateReverse(char *N1, char *N2, int Kdigit)
{
	int i;

	for (i = 0; i < Kdigit; i++)
	{
		N2[i] = N1[Kdigit - 1 - i];
	}
	N2[i] == '\0';
}
int checkPalindrome(char *N1, int Kdigit)
{
	//�迭�� ������ �� ������ ���� palindrome Ȯ��
	int i, flag = 1;
	char N2[Kdigit];

	calculateReverse(N1, N2, Kdigit);

	for (i = 0; i < Kdigit / 2; i++)
	{
		if (N1[i] != N2[i]){
			flag = 0;
			break;
		}
	}
	return flag;
}
int main(void)
{
	//n�� �ִ밪�� 10^12���̹Ƿ� ���ڿ� �迭�� �Է¹���
	//���� 16������ ��ȯ�Ҷ� ���ĺ��� �־�� �ϹǷ� ���ڿ� �迭 �̿�
	char n[14]; // 10^12�±��� ���Ƿ�.. ������ null������ +1 �ؼ� 14
	int k, i, n2, digit, N, N2, Kdigit;
	char *arr;

	// n(����), k(����)
	scanf("%s %d", n, &k);

	//�ڸ��� ���ϱ�
	for (i = 0; n[i] != '\0'; i++)
		;
	// printf("%d", i);
	digit = i;

	// n�� int������ ����
	N = changeInt(n, digit);

	// k�������� ���鶧 ���ڸ����� Ȯ��
	//Ȯ�� �� �����迭�Ҵ�
	N2 = N;
	for (i = 0; N2 > 0; i++)
		N2 /= k;
	Kdigit = i;

	// printf("Kdight: %d N: %d, digit: %d\n", Kdigit, N, digit);
	arr = (char *)malloc(sizeof(char) * (Kdigit + 1));

	// k�������� �ٲٱ�...
	changeK(arr, N, k, Kdigit);

	// test, arr ���
	/*for (i = 0; i < Kdigit; i++)
		printf("%c ", arr[i]);
	printf("\n");*/

	//palindrome check
	printf("%d\n", checkPalindrome(arr, Kdigit));

	free(arr);

	return 0;
}