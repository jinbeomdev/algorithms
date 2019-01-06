#include <stdio.h>
#include <queue>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

struct Fish {
	int y;
	int x;
	int dist;

	Fish(int y_, int x_, int dist_) : y(y_), x(x_), dist(dist_) {}
};

struct Shark {
	int y;
	int x;
	int size;
	int dist;
	int eat;

	Shark() {
		y = -1;
		x = -1;
		size = 2;
		dist = 0;
		eat = 0;
	}
};

class Comp {
public:
	bool operator() (Fish &lhs, Fish &rhs) {
		if (lhs.dist == rhs.dist) {
			if (lhs.y == rhs.y) {
				return lhs.x > rhs.x;
			}

			return lhs.y > rhs.y;
		}

		return lhs.dist > rhs.dist;
	}
};

int main() {
	int N;
	int map[20][20] = {};
	Shark shark;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int val;

			scanf("%d", &val);

			if (val == 9) {
				shark.y = i;
				shark.x = j;
				continue;
			}

			if (val > 0 && val < 9) {
				map[i][j] = val;
			}
		}
	}

	while (true) {
		bool visited[20][20];
		memset(visited, false, sizeof(visited));
		visited[shark.y][shark.x] = true;

		queue<pair<int, pair<int, int>>> q;
		q.push({ 0, { shark.y, shark.x } });

		priority_queue<Fish, vector<Fish>, Comp> pq;

		while (!q.empty()) {
			int here_y = q.front().second.first;
			int here_x = q.front().second.second;
			int here_dist = q.front().first;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int next_y = here_y + dy[i];
				int next_x = here_x + dx[i];
				
				if (next_y < 0 || next_y >= N ||
					next_x < 0 || next_x>= N) continue;

				if (visited[next_y][next_x]) continue;

				if (map[next_y][next_x] > shark.size) continue;

				if (map[next_y][next_x] > 0 && map[next_y][next_x] < 9 && map[next_y][next_x] < shark.size) {
					pq.push(Fish(next_y, next_x, here_dist + 1));
				}

				visited[next_y][next_x] = true;
				q.push({ here_dist + 1, { next_y, next_x } });
			}
		}

		if (pq.empty()) break;

		shark.y = pq.top().y;
		shark.x = pq.top().x;
		shark.dist += pq.top().dist;

		map[shark.y][shark.x] = 0;

		shark.eat++;

		if (shark.eat == shark.size) {
			shark.size++;
			shark.eat = 0;
		}

		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		if (i == shark.y && j == shark.x) {
		//			printf("S");
		//		} else {
		//			printf("%d", map[i][j]);
		//		}
		//	}
		//	puts("");
		//}
		//puts("");

	}

	printf("%d", shark.dist);
}