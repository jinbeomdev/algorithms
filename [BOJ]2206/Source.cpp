#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int iter_x[] = { 0, 1, 0, -1 };
const int iter_y[] = { -1, 0, 1, 0 };

struct POSITION {
	int x, y;
	bool is_destroyed;
	int dist;

	POSITION(int x_, int y_, bool is_destroyed_, int dist_) :
		x(x_), y(y_), is_destroyed(is_destroyed_), dist(dist_) { }
};

bool operator<(POSITION const &lhs, POSITION const &rhs) {
	return lhs.dist < rhs.dist;
}

int N, M;
vector<vector<int>> adj;
vector<vector<int>> dist;
priority_queue<POSITION> pq;

int main() {
	scanf("%d%d", &N, &M);

	adj.resize(N, vector<int>(M, 0));
	dist.resize(N, vector<int>(M, 1e9));

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

	pq.push(POSITION(0, 0, false, -1));
	dist[0][0] = 1;

	while (!pq.empty()) {
			int here_x = pq.top().x;
			int here_y = pq.top().y;
			bool here_is_destroyed = pq.top().is_destroyed;
			int here_dist = -pq.top().dist;
			pq.pop();

			if (dist[here_y][here_x] < here_dist) continue;

			for (int j = 0; j < 4; j++) {
				int next_x = here_x + iter_x[j];
				int next_y = here_y + iter_y[j];
				int next_dist = here_dist + 1;

				if (next_x < 0 || next_x >= M ||
						next_y < 0 || next_y >= N) {
					continue;
				}

				if (dist[next_y][next_x] < next_dist) continue;
				
				if (adj[next_y][next_x] == 0) {
					dist[next_y][next_x] = next_dist;
					pq.push(POSITION(next_x, next_y, here_is_destroyed, -next_dist));
				} else if (here_is_destroyed == false) {
					dist[next_y][next_x] = next_dist;
					pq.push(POSITION(next_x, next_y, true, -next_dist));
				}
		}
	}

	printf("%d", dist[N-1][M-1]);
}

/*
	시간 초과
	완전 탐색은 시간 초과가 발생함.
	가지치기를 해서 불필요한 탐색은 안하도록 해야할 듯
	아마도 다익스트라로 접근해야하나봄.
	다익스트라로 접근하면 더 짧은 경로가 있을 경우 무시하기 때문에 모든 경로를 탐색하지 않음
*/