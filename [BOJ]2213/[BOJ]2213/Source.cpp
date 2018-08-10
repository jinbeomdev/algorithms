#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> weight;
vector<vector<int>> tree;
vector<bool> visited;
vector<vector<int>> dp;
vector<int> answer;

int dfs(int root, bool check) {
	if (dp[root][check] != -1) return dp[root][check];
	int& ret = dp[root][check];
	ret = 0;

	if (check) {
		ret = weight[root];
	}

	for (int i = 0; i < tree[root].size(); i++) {
		int next = tree[root][i];

		if (!visited[next]) {
				visited[next] = true;

			if (check) {
				ret += dfs(next, false);
			}	else {
				ret += max(dfs(next, false), dfs(next, true));
			}
			
			visited[next] = false;
		}
	}

	return ret;
}

void trace(int root, bool check) {
	if (check) {
		answer.push_back(root);
		
		for (int i = 0; i < tree[root].size(); i++) {
			int next = tree[root][i];

			if (!visited[next]) {
				visited[next] = true;
				trace(next, false);
				visited[next] = false;
			}
		}
	} else {
		for (int i = 0; i < tree[root].size(); i++) {
			int next = tree[root][i];
			if (!visited[next]) {
				if (dp[next][true] < dp[next][false]) {
					visited[next] = true;
					trace(next, false);
					visited[next] = false;
				} else {
					visited[next] = true;
					trace(next, true);
					visited[next] = false;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);

	weight.clear();
	weight.resize(n, 0);
	tree.clear();
	tree.resize(n);
	visited.clear();
	visited.resize(n, false);
	dp.resize(n, vector<int>(2, -1));

	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	/*
	for (int i = 0; i < tree.size(); i++) {
		printf("%d ", i + 1);
		for (int j = 0; j < tree[i].size(); j++) {
			printf("%d ", tree[i][j] + 1);
		}
		printf("\n");
	}
	*/

	int ret = 0;
	visited[0] = true;
	ret = max(dfs(0, false), dfs(0, true));
	visited[0] = false;

	visited[0] = true;
	if (dp[0][false] < dp[0][true]) {
		trace(0, true);
	} else {
		trace(0, false);
	}
	visited[0] = false;

	sort(answer.begin(), answer.end());

	printf("%d\n", ret);
	for (int i = 0; i < answer.size(); i++) {
		printf("%d ", answer[i] + 1);
	}
}