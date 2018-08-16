#include <cstdio>
#include <cstring>

int N, M, x, y, K;
int map[20][20];
int up_down[4] = { 0, 0, 0, 0 };
int left_right[4] = {0, 0, 0, 0 };
int dx[] = {0, 1, -1, 0, 0 };
int dy[] = {0, 0, 0, -1, 1 };

void right_shift(int a[], int b[], int size = 4) {
	int temp = a[size - 1];
	for (int i = size - 1; i > 0; i--) {
		a[i] = a[i - 1];
	}
	a[0] = temp;

	b[1] = a[1];
	b[3] = a[3];
}

void left_shift(int a[], int b[], int size = 4) {
	int temp = a[0];
	for (int i = 0; i < size - 1; i++) {
		a[i] = a[i + 1];
	}
	a[size - 1] = temp;

	b[1] = a[1];
	b[3] = a[3];
}

int main() {
	scanf("%d%d%d%d%d", &N, &M, &y, &x, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		int dir;
		scanf("%d", &dir);
		if (x + dx[dir] < 0 || x + dx[dir] >= M ||
			  y + dy[dir] < 0 || y + dy[dir] >= N) {
			continue;
		}
		x = x + dx[dir]; y = y + dy[dir];
		switch (dir) {
		case 1:
			right_shift(left_right, up_down);
			break;
		case 2:
			left_shift(left_right, up_down);
			break;
		case 3:
			left_shift(up_down, left_right);
			break;
		case 4:
			right_shift(up_down, left_right);
			break;
		default:
			break;
		}
		if (map[y][x] == 0) {
			map[y][x] = left_right[3];
			left_right[3] =	up_down[3] = 0;
		} else {
			left_right[3] = up_down[3] = map[y][x];
			map[y][x] = 0;
		}
		printf("%d\n", left_right[1]);
	}
}