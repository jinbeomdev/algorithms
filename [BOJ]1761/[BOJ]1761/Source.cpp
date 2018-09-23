#include <stdio.h>
#include <string.h>

#include <vector>
#include <utility>

using namespace std;

const int LOG_MAX = 18;
const int MAX = 40001;

int parent[MAX][LOG_MAX];
int depth[MAX];
int dist[MAX];

vector<pair<int, int>> adj[MAX];

void dfs(int root) {
	for (auto child : adj[root]) {
		if (depth[child.first] == -1) {
			parent[child.first][0] = root;
			depth[child.first] = depth[root] + 1;
			dist[child.first] = dist[root] + child.second;
			dfs(child.first);
		}
	}
}

int main() {
	int N, M;

	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		int u, v, d;

		scanf("%d%d%d", &u, &v, &d);

		adj[u].push_back(make_pair(v, d));
		adj[v].push_back(make_pair(u, d));
	}

	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	memset(dist, -1, sizeof(dist));

	depth[1] = 0;
	dist[1] = 0;

	dfs(1);

	for (int i = 0; i < LOG_MAX - 1; i++) {
		for (int j = 2; j < MAX; j++) {
			if (parent[j][i] != -1) {
				parent[j][i + 1] = parent[parent[j][i]][i];
			}
		}
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int u, v;
		int temp_u, temp_v;
		
		scanf("%d%d", &u, &v);

		temp_u = u;
		temp_v = v;

		if (depth[u] < depth[v]) swap(u, v);

		int diff = depth[u] - depth[v];

		for (int i = 0; i < LOG_MAX; i++) {
			if (diff % 2 == 1) u = parent[u][i];
			diff /= 2;
		}

		if (u != v) {
			for (int j = LOG_MAX - 1; j >= 0; j--) {
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}

			u = parent[u][0];
		}

		int answer = dist[temp_u] + dist[temp_v] - 2 * dist[u];
		printf("%d\n", answer);
	}


	return 0;
}