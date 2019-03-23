#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int map[8][8];
vector<pii> zero;
vector<pii> virus;
int answer = 0;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void dfs(int idx, int num_wall, vector<pii> wall) {
	if (num_wall == 3) {
		int temp[8][8];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < wall.size(); i++) {
			temp[wall[i].first][wall[i].second] = 1;
		}

		queue<pii> q;
		for (int i = 0; i < virus.size(); i++) {
			q.push(make_pair(virus[i].first, virus[i].second));
		}

		while (!q.empty()) {
			int here_y = q.front().first;
			int here_x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int next_y = here_y + dy[i];
				int next_x = here_x + dx[i];

				if (next_y < 0 || next_y >= N ||
					next_x < 0 || next_x >= M) continue;

				if (temp[next_y][next_x] == 1) continue;

				if (temp[next_y][next_x] == 2) continue;

				temp[next_y][next_x] = 2;
				q.push(make_pair(next_y, next_x));
			}
		}

		int ret = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 0) ret++;
			}
		}

		if (answer < ret) answer = ret;

		return;
	}

	if (idx == zero.size()) return;

	wall.push_back(make_pair(zero[idx].first, zero[idx].second));
	dfs(idx + 1, num_wall + 1, wall);
	wall.pop_back();
	dfs(idx + 1, num_wall, wall);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) zero.push_back(make_pair(i, j));
			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}

	vector<pii> wall;
	dfs(0, 0, wall);
	printf("%d", answer);
}