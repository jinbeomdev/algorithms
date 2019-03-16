#include <stdio.h>
#include <queue>
#include <string.h>
#include <assert.h>
using namespace std;

int map[20][20];

int T, N, M;
int num_home;
int max_revenue;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j]) num_home++;
			}
		}

		max_revenue = num_home * M;

		int max_cost = 1;
		while (max_revenue - ((max_cost) * (max_cost) + (max_cost - 1) * (max_cost - 1)) > 0) {
			max_cost++;
		}
		max_cost--;

		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				bool discovered[20][20];
				memset(discovered, false, sizeof(discovered));
				discovered[i][j] = true;

				int depth = 1;
				int houses = map[i][j];
				while (!q.empty()) {
					int K = q.size();

					int real_revenue = (houses * M) - (depth * depth + (depth - 1) * (depth - 1));

					if (real_revenue >= 0) {
						answer = max(answer, houses);
					}

					if (depth > max_cost) {
						break;
					}

					for (int k = 0; k < K; k++) {
						int here_y = q.front().first;
						int here_x = q.front().second;
						q.pop();

						for (int l = 0; l < 4; l++) {
							int next_y = here_y + dy[l];
							int next_x = here_x + dx[l];

							if (next_y < 0 || next_y >= N ||
								next_x < 0 || next_x >= N) continue;

							if (discovered[next_y][next_x]) continue;

							q.push(make_pair(next_y, next_x));
							discovered[next_y][next_x] = true;

							if (map[next_y][next_x]) houses++;
						}
					}

					depth++;
				}
			}
		}

		printf("#%d %d\n", tc, answer);
	}
}