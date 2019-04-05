#include <stdio.h>
#include <algorithm>

using namespace std;

int T;
int N, M, C;

int map[10][10];
int psum[11][11];

int dfs(int row, int left, int right, int sum, int mul) {
	if (sum > C) return 0;
	if (left > right) {
		return mul;
	}

	int ret = 0;
	ret = max(ret, dfs(row, left + 1, right, sum + map[row][left], mul + (map[row][left] * map[row][left])));
	ret = max(ret, dfs(row, left + 1, right, sum, mul));
	return ret;
}

bool can(int ay, int ax, int by, int bx) {
	if (ax + M - 1 >= N) return false;
	if (bx + M - 1 >= N) return false;
	if (ay == by && ax <= bx && bx <= ax + M - 1) return false;
	if (ay == by && ax <= bx + M - 1 && bx <= ax) return false;
	return true;
}

int main() {
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d%d%d", &N, &M, &C);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				psum[i][j + 1] = psum[i][j] + map[i][j];
			}
		}

		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < N; l++) {
						if (!can(i, j, k, l)) continue;

						//printf("%d %d %d %d\n", i, j, k, l);
						
						//printf("%d", dfs(i, j, j + M - 1, 0, 0));
							
						//printf(" %d\n", dfs(k, l, l + M - 1, 0, 0));

						int sum = dfs(i, j, j + M - 1, 0, 0) + dfs(k, l, l + M - 1, 0, 0);
						if (answer < sum) answer = sum;
					}
				}
			}
		}

		printf("#%d %d\n", tc, answer);
	}
}