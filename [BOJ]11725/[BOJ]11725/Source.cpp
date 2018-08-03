#include <cstdio>
#include <vector>

using namespace std;

int num_node;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parents;

void dfs(int root) {
	for (int i = 0; i < adj[root].size(); i++) {
		if (!visited[adj[root][i]]) {
			visited[adj[root][i]] = true;
			parents[adj[root][i]] = root + 1;
			dfs(adj[root][i]);
		}
	}
}

int main() {
	scanf("%d", &num_node);

	adj.clear();
	adj.resize(num_node);

	visited.clear();
	visited.resize(num_node);

	parents.clear();
	parents.resize(num_node);

	for (int i = 0; i < num_node - 1; i++) {
		int node_a, node_b;
		scanf("%d%d", &node_a, &node_b);
		node_a--; node_b--;
		adj[node_a].push_back(node_b);
		adj[node_b].push_back(node_a);
	}


	visited[0] = true;
	dfs(0);

	for (int i = 1; i < num_node; i++) {
		printf("%d\n", parents[i]);
	}
}