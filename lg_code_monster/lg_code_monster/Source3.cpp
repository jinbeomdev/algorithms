#include <string>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

const int MAX = 18;
int parent[100000][MAX];
int depth[100000];
vector<int> adj[100000];

void makeTreeByDFS(int curr) {
	for (int next : adj[curr]) {
		if (depth[next] == -1) {
			parent[next][0] = curr;
			depth[next] = depth[curr] + 1;
			makeTreeByDFS(next);
		}
	}
}

vector<int> solution(int N, vector<vector<int>> directory, vector<vector<int>> query) {
	vector<int> answer;

	for (int i = 0; i < directory.size(); i++) {
		adj[directory[i][0] - 1].push_back(directory[i][1] - 1);
		adj[directory[i][1] - 1].push_back(directory[i][0] - 1);
	}

	memset(parent, -1, sizeof(parent));
	fill(depth, depth + N, -1);
	depth[0] = 0;
	makeTreeByDFS(0);

	for (int i = 0; i < query.size(); i++) {
		int u = query[i][0], v = query[i][1];

		for (int j = 0; j < MAX - 1; j++)
			for (int i = 1; i < N; i++)
				if (parent[i][j] != -1)
					parent[i][j + 1] = parent[parent[i][j]][j];

		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		for (int j = 0; diff; j++) {
			if (diff % 2) u = parent[u][j];
			diff /= 2;
		}

		if (u != v) {
			for (int j = MAX - 1; j >= 0; j--) {
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}

		answer.push_back(u + 1);
	}

	return answer;
}