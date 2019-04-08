#include <stdio.h>
#include <queue>>

using namespace std;

struct Info {
	int y, x, k;
	Info(int y_, int x_, int k_) : y(y_), x(x_), k(k_) {}
};

int K;
int W, H;
const int dy[12] = { -1, 0, 1, 0, -2, -1, 1, 2, 2, 1, -1, -2 };
const int dx[12] = { 0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1 };
int map[200][200];
int dist[200][200][31];

int main() {
	scanf("%d%d%d", &K, &W, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	queue<Info> q;
	q.push(Info(0, 0, 0));
	dist[0][0][0] = 0;

	while (!q.empty()) {
		Info here = q.front();
		q.pop();
		int here_y = here.y;
		int here_x = here.x;
		int here_k = here.k;

		for (int i = 0; i < 12; i++) {
			int next_y = here_y + dy[i];
			int next_x = here_x + dx[i];
			int next_k = here_k;

			if (next_y < 0 || next_y >= H) continue;

			if (next_x < 0 || next_x >= W) continue;

			if (i >= 4 && i < 12) next_k++;

			if (next_k > K) continue;

			if (map[next_y][next_x] == 1) continue;

			if (dist[next_y][next_x][next_k] != 0) continue;

			dist[next_y][next_x][next_k] = dist[here_y][here_x][here_k] + 1;
			q.push(Info(next_y, next_x, next_k));
		}
	}

	int answer = -1;
	for (int i = 0; i <= K; i++) {
		if (dist[H - 1][W - 1][i] == 0) continue;
		if (answer == -1) answer = dist[H - 1][W - 1][i];
		if (answer > dist[H - 1][W - 1][i]) answer = dist[H - 1][W - 1][i];
	}
	printf("%d", answer);
}