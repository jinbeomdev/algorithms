#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

struct TOWER {
	int x, y;
	int R;

	TOWER(int x_, int y_, int R_) : x(x_), y(y_), R(R_) {}
};

int T, N;
vector<TOWER> towers;
vector<vector<int>> adj;
vector<bool> visited;
int answer;

void dfs(int tower) {
	for (int i = 0; i < adj[tower].size(); i++) {
		int next_tower = adj[tower][i];
		if (!visited[next_tower]) {
			visited[next_tower] = true;
			dfs(next_tower);
		}
	}
}

bool isIncluded(int x, int y, int R, TOWER tower) {
	/* root(a^2 + b^2) = c */
	int a = abs(x - tower.x);
	int b = abs(y - tower.y);
	return R + tower.R >= sqrt(a*a + b*b);
}

void init() {
	towers.clear();
	visited.clear();
	for (int i = 0; i < adj.size(); i++) {
		adj[i].clear();
	}
	answer = 0;
}

int main() {
	scanf("%d", &T);

	for (int test_case = 0; test_case < T; test_case++) {
		init();

		scanf("%d", &N);
		towers.resize(N, TOWER(-1, -1, -1));
		visited.resize(N, false);
		adj.resize(N);

		for (int i = 0; i < N; i++) {
			int x, y, R;

			scanf("%d%d%d", &x, &y, &R);

			towers[i] = TOWER(x, y, R);

			for (int j = 0; j < i; j++) {
				if (isIncluded(x, y, R, towers[j])) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				dfs(i);
				answer++;
			}
		}

		printf("%d\n", answer);
	}

	return 0;
}