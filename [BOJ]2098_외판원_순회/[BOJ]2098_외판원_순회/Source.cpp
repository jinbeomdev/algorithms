//2098번: 외판원 순회
#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

#define __min(a,b) (((a) < (b)) ? (a) : (b))

using namespace std;

int N;
vector<vector<int>> adj;
vector<vector<int>> dp;

int tsp(int current, int visited) {
	if (visited == (1 << N) - 1) return adj[current][0];

	int& result = dp[current][visited];
	if (result != 0) return result;
	result = 987654321;
	for (int next = 0; next < N; next++) {
		if (visited&(1 << next)) continue;
		if (adj[current][next] == 0) continue;
		result = __min(result, tsp(next, visited|(1 << next)) + adj[current][next]);
	}
	return result;
}

int main() {
	cin >> N;

	adj = vector<vector<int>>(N, vector<int>(N));
	dp = vector<vector<int>>(N, vector<int>(1 << N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
		}
	}
	cout << tsp(0, 1);
}