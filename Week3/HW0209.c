#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define WIDTH 10
#define HEIGHT 10
int screen[WIDTH][HEIGHT] = {
0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
-1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
-1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
-1,-1,-1,-1, 0, 0, 0, 0, 0, 0
};
int flood_fill(int x, int y, int count) {
	int num;

	if ((x >= 0 && x < WIDTH)&& (y >= 0 && y < HEIGHT)) {//���� ����
		if (screen[x][y] == 0) {

			screen[x][y] = ++count;
			//�Ϸ� �� count�� ��ȯ, ��ȯ�ؾ� ���� �ڸ����� �̾ count�� ++��
			count = flood_fill(x, y + 1, count);
			count = flood_fill(x + 1, y, count);
			count = flood_fill(x, y - 1, count);
			count = flood_fill(x - 1, y, count);
			return count;
		}
		return count;
	}
	return count;
}
int main(void) {
	int i, j;

	for (i = 0; i < WIDTH; i++)
		for (j = 0; j < HEIGHT; j++) {
			printf("%3d", screen[i][j]);
			if (j == HEIGHT-1)
				printf("\n");
		}

	flood_fill(0, 0, 0);

	printf("\n");
	for (i = 0; i < WIDTH; i++)
		for (j = 0; j < HEIGHT; j++) {
			printf("%3d", screen[i][j]);
			if (j == HEIGHT - 1)
				printf("\n");
		}

	return 0;
}
