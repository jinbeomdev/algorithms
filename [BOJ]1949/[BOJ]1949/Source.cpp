#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> residents;
vector<vector<int>> tree;
vector<bool> visited;
vector<vector<int>> dp;

int dfs(int root, bool check) {
	int& ret = dp[root][check];

	if (ret != -1) return ret;

	ret = 0;

	if (check) {
		ret = residents[root];
	}

	for (int i = 0; i < tree[root].size(); i++) {
		int next = tree[root][i];

		if (!visited[next]) {
			visited[next] = true;

			if (check) {
				ret += dfs(next, false);
			} else {
				ret += max(dfs(next, true), dfs(next, false));
			}

			visited[next] = false;
		}
	}

	return ret;
}

int main() {
	scanf("%d", &N);
	
	residents.resize(N + 1);
	tree.resize(N + 1);
	visited.resize(N + 1, false);
	dp.resize(N + 1, vector<int>(2, -1));

	for (int i = 1; i <= N; i++) {
		scanf("%d", &residents[i]);
	}

	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	visited[1] = true;
	int ret = max(dfs(1, false), dfs(1, true));

	printf("%d", ret);
}