#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int V; //정점의 개수
vector<vector<pair<int, int>>> adj;
vector<bool> visited;

//해당 루트에서의 높이를 반환한다.
int longest = 0;
int height(int root) {
	vector<int> heights;
	for (int i = 0; i < adj[root].size(); i++) {
		if (!visited[adj[root][i].second]) {
			visited[adj[root][i].second] = true;
			heights.push_back(adj[root][i].first + height(adj[root][i].second));
		}
	}

	if (heights.empty()) return 0;

	sort(heights.begin(), heights.end());
	
	if (heights.size() >= 2) {
		longest = max(longest, heights[heights.size() - 1] + heights[heights.size() - 2]);
	}
	return heights[heights.size() - 1];
}

int main() {
	scanf("%d", &V);
	adj.resize(V);
	visited.resize(V, false);
	for (int i = 0; i < V; i++) {
		int from;
		scanf("%d", &from);
;		while (true) {
			int vertex, distance;
			scanf("%d", &vertex);
			if (vertex == -1) break;
			scanf("%d", &distance);
			adj[from - 1].push_back(make_pair(distance, vertex - 1));
		}
	}
	visited[0] = true;
	int ret = height(0);
	ret = max(ret, longest);
	printf("%d", ret);
}