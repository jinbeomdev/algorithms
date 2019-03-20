#include <stdio.h>
#include <stdlib.h>

int N, L;
int map[100][100];
int path[100];
int answer = 0;

bool check(int s, int e) {
	if (s < 0 || e >= N) return false;

	for (int i = s; i <= e; i++) {
		if (path[s] != path[i]) return false;
	}

	return true;
}

void solve() {
	bool left[100] = { false, };
	bool right[100] = { false, };

	for (int i = 0; i < N; i++) {
		if (i >= 1 && abs(path[i - 1] - path[i]) > 1) return;

		if (i >= 1 && path[i - 1] - path[i] == -1) {
			if (check(i - L, i - 1)) {
				for (int j = i - L; j <= i - 1; j++) {
					left[j] = true;
				}
			} else {
				return;
			}
		}

		if (i + 1 < N && abs(path[i] - path[i + 1] > 1)) return;

		if (i + 1 < N && path[i] - path[i + 1] == 1) {
			if (check(i + 1, i + L)) {
				for (int j = i + 1; j <= i + L; j++) {
					right[j] = true;
				}
			} else {
				return;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (left[i] && right[i]) return;
	}

	//for (int i = 0; i < N; i++) {
	//	printf("%d ", path[i]);
	//}
	//printf("\n");

	answer++;
}

int main() {
	scanf("%d%d", &N, &L);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			path[col] = map[row][col];
		}

		solve();
	}

	for (int col = 0; col < N; col++) {
		for (int row = 0; row < N; row++) {
			path[row] = map[row][col];
		}

		solve();
	}

	printf("%d", answer);
}