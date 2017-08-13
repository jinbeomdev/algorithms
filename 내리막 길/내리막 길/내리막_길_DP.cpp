#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

//세로의 크기 M, 가로의 크기 N
int M, N;
vector<vector<int>> adj;
vector<vector<int>> paths;
int X[] = {0, 1, 0, -1 };
int Y[] = {-1, 0, 1, 0 };

int dfs(int y, int x) {
	
	if (y == M - 1 && x == N - 1) return 1;
	if (paths[y][x] != -1) return paths[y][x];

	paths[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int nextY = y + Y[i];
		int nextX = x + X[i];
		if (nextY >= 0 && nextY < M &&
			nextX >= 0 && nextX < N)
			if (adj[nextY][nextX] < adj[y][x]) {
				paths[y][x] += dfs(nextY, nextX);
			}
	}

	return paths[y][x];
}

int main() {
	cin >> M >> N;

	adj = vector<vector<int>>(M, vector<int>(N, 0));
	paths = vector<vector<int>>(M, vector<int>(N, -1));

	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			scanf("%d", &adj[i][j]);
		}
	}

	printf("%d", dfs(0, 0));
}