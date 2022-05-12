#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void display(char b[][3]) {
	int i, j;

	printf("    ");

	for (i = 0; i < 3; i++)
		printf("%2d", i);

	printf("\n     -----\n");

	for (i = 0; i < 3; i++) {
		printf("%3d |", i);
		for (j = 0; j < 3; j++)
			printf("%1c ", b[i][j]);
		printf("\n");
	}
}
int winCheck(char b[][3], int count, int row, int column) {
	char ply;
	int i, j;
	int wC=0;

	if (count % 2 == 1)
		ply = 'X';
	else if(count % 2 == 0)
		ply = 'O';


	//���ڸ��� �������� ����, ����, �밢��, ���밢�� ���

	//����
	wC = 1; //���ڸ� 1�� �־���
	//������
	
	for (i = column+1; i < 3; i++)
		if (b[row][i] == ply)
			wC++;
		else
			break;

	//����
	for (i = column-1; i >= 0; i--)
		if (b[row][i] == ply)
			wC++;
		else
			break;

	//printf("%d\n", wC);
	if (wC == 3)
		return 1;
	
	
	//����
	wC = 1;
	//��
	for (i = row-1; i >= 0; i--)
		if (b[i][column] == ply)
			wC++;
		else
			break;

	// �Ʒ�
	for (i = row+1; i < 3; i++)
		if (b[i][column] == ply)
			wC++;
		else
			break;
	
	//printf("%d\n", wC);
	if (wC == 3)
		return 1;
	
	
	
	//�밢��
	wC = 1;
	//��������
	i = row - 1;
	j = column + 1;

	while (i >= 0 && j < 3 && b[i][j] == ply) {
		wC++;
		i--;
		j++;
	}



	//���ʾƷ�
	i = row + 1;
	j = column - 1;

	while (i <3 && j >= 0 && b[i][j] == ply) {
		wC++;
		i++;
		j--;
	}

	//printf("%d\n", wC);
	if (wC == 3)
		return 1;
	


	//���밢��
	wC = 1;
	//���� ��
	i = row - 1;
	j = column - 1;

	while (i >= 0 && j >= 0 && b[i][j] == ply) {
		wC++;
		i--;
		j--;
	}

	//������ �Ʒ�
	i = row + 1;
	j = column + 1;

	while (i < 3 && j < 3 && b[i][j] == ply) {
		wC++;
		i++;
		j++;
	}
	//printf("%d\n", wC);

	if (wC == 3)
		return 1;
	else
		return 0;
}
int main(void) {
	char board[3][3];
	int i, j, cnt = 0;
	int r, c; //�Է¹޴� ��
	char player1 = 'X';
	char player2 = 'O';

	//cnt�� �����, Ȧ���϶� X, ¦���϶� O��� �ν�


	//���� �� �ʱ�ȭ
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			board[i][j] = ' ';

	//do-while�� �Է¹ޱ�
	do {
		display(board);

		if (cnt % 2 == 0) {
			do {
				printf("Player %c(�� ��):", player1);
				scanf("%d %d", &r, &c);
					
			} while (board[r][c] != ' ');//���ǽ��� true�� ��� �ݺ�
			board[r][c] = player1;
			cnt++;
			
		}

		else if (cnt % 2 == 1) {
			do {
				printf("Player %c(�� ��):", player2);
				scanf("%d %d", &r, &c);

			} while (board[r][c] != ' ');
			board[r][c] = player2;
			cnt++;
		}
		
		
	} while (cnt != 9&&winCheck(board, cnt, r, c)!=1);//9ȸ�� ��� ����ǰų� winCheck�� 1�϶�

	display(board);
	
	//���� winCheck�� 1�̸� player wins ���, �ƴϸ� nobody wins ���
	//���� �̱���� Ȯ���� cnt Ȧ¦���� ����
	if (winCheck(board, cnt, r, c) == 1)
		if (cnt % 2 == 0)
			printf("Player 0 wins!\n");
		else
			printf("Player X wins!\n");
	else
		printf("Nobody wins!\n");



	return 0;
}