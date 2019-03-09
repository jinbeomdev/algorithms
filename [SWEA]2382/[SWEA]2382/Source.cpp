#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
	int y, x, n, d;
	bool alive = true;
};

int T, N, M, K;

const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, -1, 1 };
const int rd[] = { 1, 0, 3, 2 };

vector<pair<Data, int>> map[100][100];

bool comp(const pair<Data, int>& a, const pair<Data, int>& b) {
	return a.first.n < b.first.n;
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		Data micro[1000];

		scanf("%d%d%d", &N, &M, &K);

		for (int i = 0; i < K; i++) {
			scanf("%d%d%d%d", &micro[i].y, &micro[i].x, &micro[i].n, &micro[i].d);
			micro[i].d--;
		}

		for (int i = 0; i < M; i++) {

			for (int j = 0; j < K; j++) {
				if (!micro[j].alive) continue;

				micro[j].y += dy[micro[j].d];
				micro[j].x += dx[micro[j].d];
				
				if (micro[j].y == 0 || micro[j].y == N - 1 || micro[j].x == 0 || micro[j].x == N - 1) {
					micro[j].n /= 2;
					micro[j].d = rd[micro[j].d];
					if (micro[j].n == 0) micro[j].alive = false;
				} else {
					map[micro[j].y][micro[j].x].push_back(make_pair(micro[j], j));
				}
			}

			for (int j = 1; j < N - 1; j++) {
				for (int k = 1; k < N - 1; k++) {
					if (map[j][k].size() > 1) {
						sort(map[j][k].begin(), map[j][k].end(), comp);

						int sum = 0;

						for (int l = 0; l < map[j][k].size() - 1; l++) {
							sum += map[j][k][l].first.n;
							micro[map[j][k][l].second].alive = false;
						}

						micro[map[j][k].back().second].n += sum;
					}
					map[j][k].clear();
				}
			}	
		}

		int answer = 0;
		for (int i = 0; i < K; i++) {
			if (micro[i].alive) answer += micro[i].n;
		}

		printf("#%d %d\n", tc, answer);
	}
}