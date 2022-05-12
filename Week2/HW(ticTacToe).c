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


	//내자리를 기준으로 수평, 수직, 대각선, 역대각선 계산

	//수평
	wC = 1; //제자리 1값 주어짐
	//오른쪽
	
	for (i = column+1; i < 3; i++)
		if (b[row][i] == ply)
			wC++;
		else
			break;

	//왼쪽
	for (i = column-1; i >= 0; i--)
		if (b[row][i] == ply)
			wC++;
		else
			break;

	//printf("%d\n", wC);
	if (wC == 3)
		return 1;
	
	
	//수직
	wC = 1;
	//위
	for (i = row-1; i >= 0; i--)
		if (b[i][column] == ply)
			wC++;
		else
			break;

	// 아래
	for (i = row+1; i < 3; i++)
		if (b[i][column] == ply)
			wC++;
		else
			break;
	
	//printf("%d\n", wC);
	if (wC == 3)
		return 1;
	
	
	
	//대각선
	wC = 1;
	//오른쪽위
	i = row - 1;
	j = column + 1;

	while (i >= 0 && j < 3 && b[i][j] == ply) {
		wC++;
		i--;
		j++;
	}



	//왼쪽아래
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
	


	//역대각선
	wC = 1;
	//왼쪽 위
	i = row - 1;
	j = column - 1;

	while (i >= 0 && j >= 0 && b[i][j] == ply) {
		wC++;
		i--;
		j--;
	}

	//오른쪽 아래
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
	int r, c; //입력받는 값
	char player1 = 'X';
	char player2 = 'O';

	//cnt를 만들고, 홀수일때 X, 짝수일때 O라고 인식


	//보드 값 초기화
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			board[i][j] = ' ';

	//do-while로 입력받기
	do {
		display(board);

		if (cnt % 2 == 0) {
			do {
				printf("Player %c(행 열):", player1);
				scanf("%d %d", &r, &c);
					
			} while (board[r][c] != ' ');//조건식이 true인 경우 반복
			board[r][c] = player1;
			cnt++;
			
		}

		else if (cnt % 2 == 1) {
			do {
				printf("Player %c(행 열):", player2);
				scanf("%d %d", &r, &c);

			} while (board[r][c] != ' ');
			board[r][c] = player2;
			cnt++;
		}
		
		
	} while (cnt != 9&&winCheck(board, cnt, r, c)!=1);//9회가 모두 진행되거나 winCheck가 1일때

	display(board);
	
	//만약 winCheck가 1이면 player wins 출력, 아니면 nobody wins 출력
	//누가 이긴건지 확인은 cnt 홀짝으로 구분
	if (winCheck(board, cnt, r, c) == 1)
		if (cnt % 2 == 0)
			printf("Player 0 wins!\n");
		else
			printf("Player X wins!\n");
	else
		printf("Nobody wins!\n");



	return 0;
}