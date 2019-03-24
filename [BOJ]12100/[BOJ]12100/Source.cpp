#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[20][20];

int dfs(int idx) {
	if (idx == 5) {
		int ret = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret = max(ret, map[i][j]);
			}
		}
		return ret;
	}

	int ret = 0;
	int temp[20][20];
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			temp[j][k] = map[j][k];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N; j++) {
			vector<int> v;
			for (int k = 0; k < N; k++) {
				if (i < 2 && map[j][k] != 0) {
					v.push_back(map[j][k]);
				}

				if (i >= 2 && map[k][j] != 0) {
					v.push_back(map[k][j]);
				}
			}

			if (i == 1 || i == 3) reverse(v.begin(), v.end());

			vector<int> m;
			for (int k = 0; k < v.size(); k++) {
				if (k + 1 < v.size() && v[k] == v[k + 1]) {
					m.push_back(v[k] * 2);
					k++;
				} else {
					m.push_back(v[k]);
				}
			}

			for (int k = m.size(); k < N; k++) m.push_back(0);

			if (i == 1 || i == 3) reverse(m.begin(), m.end());

			for (int k = 0; k < N; k++) {
				if (i < 2) map[j][k] = m[k];
				if (i >= 2) map[k][j] = m[k];
			}
		}

		ret = max(ret, dfs(idx + 1));
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				map[j][k] = temp[j][k];
			}
		}
	}

	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d", dfs(0));
}