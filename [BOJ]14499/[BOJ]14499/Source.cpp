#include <stdio.h>

int dice[7] = { 0, 0, 0, 0, 0, 0, 0};
int N, M, dice_y, dice_x, K;
int map[20][20];
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void move(int d) {
	int temp[7];
	if (d == 1) {
		temp[1] = dice[3];
		temp[2] = dice[2];
		temp[3] = dice[6];
		temp[4] = dice[1];
		temp[5] = dice[5];
		temp[6] = dice[4];
	} else if (d == 2) {
		temp[1] = dice[4];
		temp[2] = dice[2];
		temp[3] = dice[1];
		temp[4] = dice[6];
		temp[5] = dice[5];
		temp[6] = dice[3];
	} else if (d == 3) {
		temp[1] = dice[2];
		temp[2] = dice[6];
		temp[3] = dice[3];
		temp[4] = dice[4];
		temp[5] = dice[1];
		temp[6] = dice[5];
	} else {
		temp[1] = dice[5];
		temp[2] = dice[1];
		temp[3] = dice[3];
		temp[4] = dice[4];
		temp[5] = dice[6];
		temp[6] = dice[2];
	}

	for (int i = 1; i < 7; i++) {
		dice[i] = temp[i];
	}
}

int main() {
	scanf("%d%d%d%d%d", &N, &M, &dice_y, &dice_x, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		int d;
		scanf("%d", &d);
		int next_y = dice_y + dy[d];
		int next_x = dice_x + dx[d];

		if (next_y < 0 || next_y >= N ||
			next_x < 0 || next_x >= M) continue;

		dice_y = next_y;
		dice_x = next_x;

		move(d);
		if (map[dice_y][dice_x] == 0) {
			map[dice_y][dice_x] = dice[1];
		} else {
			dice[1] = map[dice_y][dice_x];
			map[dice_y][dice_x] = 0;
		}

		printf("%d\n", dice[6]);
	}
}