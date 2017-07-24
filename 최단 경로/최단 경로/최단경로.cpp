#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define INT_MAX       2147483647    // maximum (signed) int value

int main() {
	int V, E;
	int start;
	//pair<인접한 정점, 가중치>
	vector<vector<pair<int, int>>> adj;
	vector<int> distance;
	//priority_queue<pair<인정한 정점, 가중치>>
	priority_queue<pair<int, int>> pq;

	cin >> V >> E;
	cin >> start;

	adj = vector<vector<pair<int, int>>>(V + 1);
	distance = vector<int>(V + 1, INT_MAX);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}

	distance[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (distance[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int nextDistance = cost + adj[here][i].second;
			int there = adj[here][i].first;

			if (distance[there] > nextDistance) {
				distance[there] = nextDistance;
				pq.push(make_pair(-nextDistance, there));
			}
		}
	}

	for (int i = 1; i < distance.size(); i++) {
		if (distance[i] == INT_MAX)
			cout << "INF";
		else
			cout << distance[i];
		cout << endl;
	}
}