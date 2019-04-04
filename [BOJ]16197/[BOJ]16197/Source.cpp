#include <stdio.h>

char map[20][20];
int N, M;

int a_y = -1;
int a_x = -1;
int b_y = -1;
int b_x = -1;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int answer = 11;

void dfs(int cnt, int ay, int ax, int by, int bx) {
	if (cnt > 10) return;

	bool aisfalled = false;
	bool bisfalled = false;

	if (ay < 0 || ay >= N || ax < 0 || ax >= M) {
		aisfalled = true;
	}

	if (by < 0 || by >= N || bx < 0 || bx >= M) {
		bisfalled = true;
	}

	if (aisfalled && bisfalled) return;

	if (aisfalled || bisfalled) {
		if (answer > cnt) answer = cnt;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextay = ay + dy[i];
		int nextax = ax + dx[i];
		int nextby = by + dy[i];
		int nextbx = bx + dx[i];

		if (map[nextay][nextax] == '#') {
			nextay = ay;
			nextax = ax;
		}

		if (map[nextby][nextbx] == '#') {
			nextby = by;
			nextbx = bx;
		}

		dfs(cnt + 1, nextay, nextax, nextby, nextbx);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &map[i][j]);

			if (map[i][j] == 'o') {
				if (a_y == -1 && a_x == -1) {
					a_y = i;
					a_x = j;
				}
				else {
					b_y = i;
					b_x = j;
				}
				map[i][j] = '.';
			}
		}
	}

	dfs(0, a_y, a_x, b_y, b_x);

	printf("%d", (answer == 11) ? -1 : answer);
}