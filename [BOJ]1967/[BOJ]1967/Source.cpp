#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;
int N;
int longest;

int height(int root) {
	vector<int> heights;
	for (int i = 0; i < adj[root].size(); i++) {
		heights.push_back(adj[root][i].second + height(adj[root][i].first));
	}

	if (heights.empty()) return 0;

	sort(heights.begin(), heights.end());
	
	if (heights.size() >= 2) {
		longest = max(longest, heights[heights.size() - 1] + heights[heights.size() - 2]);
	}

	return heights[heights.size() - 1];
}

int main() {
	scanf("%d", &N);
	adj.resize(N);
	for (int i = 0; i < N - 1; i++) {
		int parent;
		int child;
		int weight;
		scanf("%d%d%d", &parent, &child, &weight);
		adj[parent - 1].push_back(make_pair(child - 1, weight));
	}

	int ret = height(0);

	printf("%d", (ret > longest) ? ret : longest);
}