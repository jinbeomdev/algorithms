#include <stdio.h>
#include <queue>

using namespace std;

struct Info {
	int y, x, k;
	Info(int y_, int x_, int k_) : y(y_), x(x_), k(k_) {}
};

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int N, M, K;
int map[1000][1000];
bool discovered[1000][1000][11];
int dist[1000][1000][11];


int main() {
	scanf("%d%d%d", &N, &M, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	queue<Info> q;
	q.push(Info(0, 0, 0));
	discovered[0][0][0] = true;
	dist[0][0][0] = 1;

	while (!q.empty()) {
		Info here = q.front();
		int here_y = here.y;
		int here_x = here.x;
		int here_k = here.k;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = here_y + dy[i];
			int next_x = here_x + dx[i];
			int next_k;
			
			if (next_y < 0 || next_y >= N) continue;

			if (next_x < 0 || next_x >= M) continue;

			if (map[next_y][next_x] == 1) {
				next_k = here_k + 1;
				if (next_k > K) continue;
				if (discovered[next_y][next_x][next_k]) continue;
				discovered[next_y][next_x][next_k] = true;
				dist[next_y][next_x][next_k] = dist[here_y][here_x][here_k] + 1;
				q.push(Info(next_y, next_x, next_k));
			}
			else {
				next_k = here_k;
				if (discovered[next_y][next_x][next_k]) continue;
				discovered[next_y][next_x][next_k] = true;
				dist[next_y][next_x][next_k] = dist[here_y][here_x][here_k] + 1;
				q.push(Info(next_y, next_x, next_k));
			}
		}
	}

	int answer = -1;
	for (int i = 0; i <= K; i++) {
		if (!discovered[N - 1][M - 1][i])continue;
		if (answer == -1) answer = dist[N - 1][M - 1][i];
		else {
			if (answer > dist[N - 1][M - 1][i]) answer = dist[N - 1][M - 1][i];
		}
	}
	printf("%d", answer);
}