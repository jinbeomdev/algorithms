#include <stdio.h>
#include <string.h>

struct Pos {
	int x;
	int y;

	Pos() {}
	Pos(int x_, int y_) : x(x_), y(y_) {}
};

struct Wh {
	int first_x, first_y;
	int second_x, second_y;

	Wh() {
		first_x = first_y = second_x = second_y = 0;
	}

	void init() {
		first_x = first_y = second_x = second_y = 0;
	}

	void add(int x, int y) {
		if (!first_x && !first_y) {
			first_x = x; first_y = y;
		} else {
			second_x = x; second_y = y;
		}
	}

	Pos getPos(int x, int y) {
		if (first_x == x && first_y == y) {
			return Pos(second_x, second_y);
		} else {
			return Pos(first_x, first_y);
		}
	}
}wh[11];

int T, N;
int map[101][101];
int ans;

const int dpos[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
const int block[6][4] = { {0, 0, 0, 0}, {2, 3, 1, 0}, {1, 3, 0, 2,}, {3, 2, 0, 1}, {2, 0, 3, 1}, {2, 3, 0, 1} };

void dfs(Pos cur, int dir, int cnt) {
	if (ans < cnt) ans = cnt;
	do {
		cur.y = cur.y + dpos[dir][0];
		cur.x = cur.x + dpos[dir][1];
	} while (!map[cur.y][cur.x]);
	if (map[cur.y][cur.x] == -1) return;
	if (map[cur.y][cur.x] <= 5) {
		dir = block[map[cur.y][cur.x]][dir];
		dfs(cur, dir, cnt + 1);
	} else {
		Pos p = wh[map[cur.y][cur.x]].getPos(cur.x, cur.y);
		cur.y = p.y;
		cur.x = p.x;

		dfs(cur, dir, cnt);
	}
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < 11; i++) {
			wh[i].init();
		}
		scanf("%d", &N);
		for (int i = 0; i <= N + 1; i++) map[i][0] = map[0][i] = map[i][N + 1] = map[N + 1][i] = 5;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] > 5) {
					wh[map[i][j]].add(j, i);
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!map[i][j]) {
					for (int k = 0; k < 4; k++) {
						map[i][j] = -1;
						dfs(Pos(j, i), k, 0);
						map[i][j] = 0;
					}
				}
			}
		}
		printf("#%d %d\n", tc, ans);
	}
}