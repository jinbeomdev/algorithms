#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

int N;
int map[500][500][2];
bool discovered[500][500];
int dist[500][500];
pii path[500][500];

const int dy0[] = { -1, -1, 0, 1, 1, 0 };
const int dx0[] = { -1, 0, 1, 0, -1, -1 };
const int dy1[] = { -1, -1 ,0 , 1, 1, 0 };
const int dx1[] = { 0, 1, 1, 1, 0, -1 };

bool can(int ny, int nx) {
	if (ny < 0 || ny >= N) return false;
	if (ny % 2 == 0) {
		return nx >= 0 && nx < N;
	} else {
		return nx >= 0 && nx < N - 1;
	}
}

bool go(int y, int x, int ny, int nx) {
	if (y == ny) {
		if (x < nx) {
			return map[y][x][1] == map[ny][nx][0];
		} else {
			return map[y][x][0] == map[ny][nx][1];
		}
	} else {
		if (y % 2 == 0) {
			if (x == nx) {
				return map[y][x][1] == map[ny][nx][0];
			} else {
				return map[y][x][0] == map[ny][nx][1];
			}
		} else {
			if (x == nx) {
				return map[y][x][0] == map[ny][nx][1];
			} else {
				return map[y][x][1] == map[ny][nx][0];
			}
		}
	}
}

int sum(int y, int x) {
	int answer = y / 2 * (N * 2 - 1);
	if (y % 2 == 1) {
		answer += N;
	}
	answer += x + 1;
	return answer;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < N; j++) {
				scanf("%d%d", &map[i][j][0], &map[i][j][1]);
			}
			} else {
				for (int j = 0; j < N - 1; j++) {
				scanf("%d%d", &map[i][j][0], &map[i][j][1]);
			}
		}
	}

	queue<pii> q;
	q.push(make_pair(0, 0));
	discovered[0][0] = true;
	dist[0][0] = 1;

	while (!q.empty()) {
		int here_y = q.front().first;
		int here_x = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int next_y, next_x;
			if (here_y % 2 == 0) {
				next_y = here_y + dy0[i];
				next_x = here_x + dx0[i];
			} else {
				next_y = here_y + dy1[i];
				next_x = here_x + dx1[i];
			}

			if (!can(next_y, next_x)) continue;

			if (!go(here_y, here_x, next_y, next_x)) continue;

			if (discovered[next_y][next_x]) continue;

			discovered[next_y][next_x] = true;
			dist[next_y][next_x] = dist[here_y][here_x] + 1;
			path[next_y][next_x] = make_pair(here_y, here_x);
			q.push(make_pair(next_y, next_x));
		}
	}

	int y = N - 1;
	int x = N - 1;
	while (discovered[y][x] == false) {
		x -= 1;
		if (x < 0) {
			y -= 1;
			x = N - 1;
			if (y % 2 == 1) {
				x -= 1;
			}
		}
	}
	printf("%d\n", dist[y][x]);

	stack<pii> s;
	while (!(x == 0 && y == 0)) {
		s.push(make_pair(y, x));
		int y_ = y;
		int x_ = x;
		y = path[y_][x_].first;
		x = path[y_][x_].second;
	}
	s.push(make_pair(y, x));

	while (!s.empty()) {
		int y = s.top().first;
		int x = s.top().second;
		s.pop();
		printf("%d ", sum(y, x));
	}
}