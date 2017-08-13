#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> adj;
vector<vector<long long>> dp;


int dfs(int y, int x) {
	if (y == N - 1 && x == N - 1) {
		return 1;
	}

	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	dp[y][x] = 0;

	int downY = y + adj[y][x], downX = x;
	int rightY = y, rightX = x + adj[y][x];

	if (downY >= 0 && downY < N && downX >= 0 && downX < N) dp[y][x] += dfs(downY, downX);
	if (rightY >= 0 && rightY < N && rightX >= 0 && rightX < N) dp[y][x] += dfs(rightY, rightX);

	return dp[y][x];
}

int main() {
	cin >> N;

	adj = vector<vector<int>>(N, vector<int>(N, 0));
	dp = vector<vector<long long>>(N, vector< long long>(N, -1));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
		}
	}
	
	cout << dfs(0, 0) << endl;
}