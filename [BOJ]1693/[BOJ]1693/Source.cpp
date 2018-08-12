#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> tree;
vector<vector<int>> dp;

void getTree(int parent, int child) {
	visited[child] = true;

	if (child != 1) tree[parent].push_back(child);

	for (int i = 0; i < adj[child].size(); i++) {
		int next = adj[child][i];

		if (!visited[next]) {
			getTree(child, next);
		}
	}
}

int paintTree(int root, int color) {
	int& ret = dp[root][color]; //해당 root를 해당 color를 칠했을 때 최소 비용

	if (ret != -1) return ret;

	ret = color;

	for (int i = 0; i < tree[root].size(); i++) {
		int next = tree[root][i];
		int min_value = 1e9;

		for (int j = 1; j < 16; j++) {
				if (j != color) {
					min_value = min(min_value, paintTree(next, j));
				}
			}
			ret += min_value;
		}

	return ret;
}

int main() {
	scanf("%d", &N);

	adj.resize(N + 1);
	visited.resize(N + 1, false);
	tree.resize(N + 1);
	dp.resize(N + 1, vector<int>(16, -1));

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	getTree(0, 1);
	int ret = 1e9;
	for (int i = 1; i < 16; i++) {
		ret = min(ret, paintTree(1, i));
	}

	printf("%d", ret);
}