#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int T;
int n, m, t;
int s, g, h;

vector<vector<pair<int, int>>> adj; //<cost, connected vertex>
vector<int> xd;
vector<int> yd;
vector<bool> dests;

void FindShortestPath(int source, vector<int> &dist) {
	priority_queue<pair<int, int>> pq; //cost, vertex
	
	pq.push(make_pair(0, source));
	dist[source] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (pair<int, int> next_vertex : adj[here]) {

			int next_cost = cost + next_vertex.first;
			int next = next_vertex.second;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push(make_pair(-next_cost, next));
			}
		}
	}
}

int main() {
	scanf("%d", &T);

	for (int test_case = 0; test_case < T; test_case++) {
		scanf("%d%d%d%d%d%d", &n, &m, &t, &s, &g, &h);

		s--; g--; h--;

		adj.clear();
		xd.clear();
		yd.clear();
		dests.clear();

		adj.resize(n);
		xd.resize(n, 1e9);
		yd.resize(n, 1e9);
		dests.resize(n, false);

		for (int road = 0; road < m; road++) {
			int a, b, c;
			
			scanf("%d%d%d", &a, &b, &c);

			a--; b--; c; //for index

			adj[a].push_back(make_pair(c, b));
			adj[b].push_back(make_pair(c, a));
		}

		for (int i = 0; i < t; i++) {
			int dest;

			scanf("%d", &dest);

			dest--;

			dests[dest] = true;
		}
		
		FindShortestPath(s, xd);

		int bridge = xd[g] < xd[h] ? h : g;

		FindShortestPath(bridge, yd);

		for (int i = 0; i < n; i++) {
			if (!dests[i]) continue;
			if (xd[i] == xd[bridge] + yd[i]) {
				printf("%d ", i + 1);
			}
		}
		puts("");
	}
}