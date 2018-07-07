#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int iter_x[] = { 0, 1, 0, -1 };
const int iter_y[] = { -1, 0, 1, 0 };

struct POSITION {
	int x, y;
	bool is_destroyed;

	POSITION(int x_, int y_, bool is_destroyed_) :
		x(x_), y(y_), is_destroyed(is_destroyed_) { }
};

int N, M;
vector<vector<int>> adj;
vector<vector<bool>> visited;
queue<POSITION> q;

int main() {
	scanf("%d%d", &N, &M);

	adj.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<bool>(M, false));

	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[j].size(); j++) {
			char c;
			scanf("%c", &c);

			if (c == '\n') {
				j--;
				continue;
			}

			adj[i][j] = (int)(c - '0');
		}
	}

	q.push(POSITION(0, 0, false));
	visited[0][0] = true;

	int depth = 1;
	bool is_arrived = false;
	while (!q.empty()) {
		int q_size = q.size();

		for (int i = 0; i < q_size; i++) {
			int here_x = q.front().x;
			int here_y = q.front().y;
			bool here_is_destroyed = q.front().is_destroyed;
			q.pop();

			if (here_x == M - 1 && here_y == N - 1) {
				is_arrived = true;
				break;
			}

			for (int j = 0; j < 4; j++) {
				int next_x = here_x + iter_x[j];
				int next_y = here_y + iter_y[j];

				if (next_x < 0 || next_x >= M ||
						next_y < 0 || next_y >= N) {
					continue;
				}


				if (!visited[next_y][next_x]) {
					if (adj[next_y][next_x] == 0) {
						visited[next_y][next_x] = true;
						q.push(POSITION(next_x, next_y, here_is_destroyed));
					} else if (here_is_destroyed == false) {
						visited[next_y][next_x] = true;
						q.push(POSITION(next_x, next_y, true));
					}
				}
			}
		}

		if (is_arrived) break;

		depth++;
	}

	printf("%d", depth);
}

/*
	시간 초과
	완전 탐색은 시간 초과가 발생함.
	가지치기를 해서 불필요한 탐색은 안하도록 해야할 듯
	아마도 다익스트라로 접근해야하나봄.
	다익스트라로 접근하면 더 짧은 경로가 있을 경우 무시하기 때문에 모든 경로를 탐색하지 않음
*/