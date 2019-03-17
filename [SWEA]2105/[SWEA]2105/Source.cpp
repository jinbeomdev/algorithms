#include <stdio.h>

int T, N;
int map[20][20];
bool desert[101];
bool visited[20][20];
int answer;
int start_x;
int start_y;

const int dx[] = { 1, -1, -1, 1 };
const int dy[] = { 1, 1, -1, -1 };

void solve(int dir, int cnt, int y, int x) {
	if (dir == 3 && y == start_y && x == start_x) {
		if (answer < cnt) answer = cnt;
		return;
	}

	for (int i = 0; i < 2; i++) {
		if (dir == 3 && i == 1) break;

		int next_y = y + dy[dir + i];
		int next_x = x + dx[dir + i];

		if (next_y < 0 || next_y >= N ||
			next_x < 0 || next_x >= N)
			continue;

		if (visited[next_y][next_x]) continue;

		int next_desert = map[next_y][next_x];
		if (desert[next_desert]) continue;

		visited[next_y][next_x] = true;
		desert[next_desert] = true;

		solve(dir + i, cnt + 1, next_y, next_x);

		visited[next_y][next_x] = false;
		desert[next_desert] = false;
	}
}

int main() {
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				visited[i][j] = false;
			}
		}

		answer = -1;
		for (int i = 0; i < 101; i++) {
			desert[i] = false;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				start_y = i;
				start_x = j;

				int next_y = i + dy[0];
				int next_x = j + dx[0];

				if (next_y < 0 || next_y >= N ||
					next_x < 0 || next_x >= N)
					continue;

				int next_desert = map[next_y][next_x];
				visited[next_y][next_x] = true;
				desert[next_desert] = true;

				solve(0, 1, next_y, next_x);

				visited[next_y][next_x] = false;
				desert[next_desert] = false;
			}
		}

		printf("#%d %d\n", tc, answer);
	}
}