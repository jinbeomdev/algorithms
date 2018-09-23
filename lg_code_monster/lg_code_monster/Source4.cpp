#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int parent[MAX][18];
int depth[MAX];
vector<int> adj[MAX];
int count_;

bool _findRoot(int N, int root, vector<bool>& visited) {
	bool is_root = false;

	for (int i = 0; i < adj[root].size(); i++) {
		if (!visited[adj[root][i]]) {
			visited[adj[root][i]] = true;
			is_root = _findRoot(N, adj[root][i], visited);
			count_++;
		}
	}

	if (count_ == N) {
		return true;
	}

	return is_root;
}

int FindRoot(int N) {

	for (int i = 1; i <= N; i++) {
		vector<bool> visited = vector<bool>(N + 1, false);
		visited[i] = true;
		count_ = 1;
		if (_findRoot(N, i, visited)) {
			return i;
		}
	}

	return -1;
}

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
	for (int i = 0; i < directory.size(); i++) {
		adj[directory[i][0]].push_back(directory[i][1]);
	}

	int d = FindRoot(N);

	memset(parent, -1, sizeof(parent));
	fill(depth, depth + N + 1, -1);
	makeTreeByDFS(d);
	
	vector<int> answer;

	for (int j = 0; j<17; j++)
		for (int i = 1; i<=N; i++)
			if (parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];

	for(int i = 0; i < query.size(); i++) {
		int u = query[i][0], v = query[i][1];
		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		for (int j = 0; diff; j++) {
			if (diff % 2) u = parent[u][j];
			diff /= 2;
		}

		if (u != v) {
			for (int j = 17; j >= 0; j--) {
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}

		int x = (depth[query[i][0]] + 2 + depth[query[i][1]] + 2) - ((depth[u] + 2) * 2) + 1;
		answer.push_back(x);
	}
	return answer;
}

int main() {
	//5, [[1, 2], [1, 3], [2, 4], [2, 5]], [[1, 5], [2, 5], [3, 5], [4, 5]]

	vector<vector<int>> direc;
	vector<int> item;
	item.push_back(1);
	item.push_back(2);
	direc.push_back(item);
	item.clear();

	item.push_back(1);
	item.push_back(3);
	direc.push_back(item);
	item.clear();

	item.push_back(2);
	item.push_back(4);
	direc.push_back(item);
	item.clear();

	item.push_back(2);
	item.push_back(5);
	direc.push_back(item);
	item.clear();

	vector<vector<int>> b;
	item.push_back(1);
	item.push_back(5);
	b.push_back(item);
	item.clear();

	item.push_back(2);
	item.push_back(5);
	b.push_back(item);
	item.clear();

	item.push_back(3);
	item.push_back(5);
	b.push_back(item);
	item.clear();

	item.push_back(4);
	item.push_back(5);
	b.push_back(item);
	item.clear();

	solution(5, direc, b);
}