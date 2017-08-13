#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int X[] = { 0, 1, 0, -1 };
int Y[] = { -1, 0, 1, 0 };

int main() {
	//세로의 크기 M, 가로의 크기 N
	int M, N;
	vector<vector<int>> adj;
	vector<vector<int>> paths;
	queue<pair<int, int>> q;

	cin >> M >> N;

	adj = vector<vector<int>>(M, vector<int>(N, 0));
	paths = vector<vector<int>>(M, vector<int>(N, 0));

	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			cin >> adj[i][j];
		}
	}

	paths[0][0] = 1;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			if (y + Y[k] >= 0 && y + Y[k] < M && x + X[k] >= 0 && x + X[k] < N)
				if (adj[y][x] > adj[y + Y[k]][x + X[k]]) {
					paths[y + Y[k]][x + X[k]]++;
					q.push(make_pair(y + Y[k], x + X[k]));
				}
		}
	}

	cout << paths[M - 1][N - 1];
}