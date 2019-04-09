#include <stdio.h>

int N;

char map[100][100];
bool visited[100][100];
bool visited2[100][100];

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, char start) {
	if (visited[y][x]) return;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_y >= N) continue;
		if (next_x < 0 || next_x >= N) continue;
		if (map[next_y][next_x] != start) continue;
		dfs(next_y, next_x, start);
	}
}

void dfs2(int y, int x, char start) {
	if (visited2[y][x]) return;
	visited2[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_y >= N) continue;
		if (next_x < 0 || next_x >= N) continue;
		if ((start == 'R' || start == 'G') && map[next_y][next_x] == 'B') continue;
		if (start == 'B' && (map[next_y][next_x] == 'R' || map[next_y][next_x] == 'G')) continue;
		dfs2(next_y, next_x, start);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	int a = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				a++;
				dfs(i, j, map[i][j]);
			}
		}
	}

	int b = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited2[i][j]) {
				b++;
				dfs2(i, j, map[i][j]);
			}
		}
	}

	printf("%d %d", a, b);
}