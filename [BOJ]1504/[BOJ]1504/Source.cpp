//1504번: 특정한 최단 경로
//INF의 값을 잘 선택하자. 오버플로우가 나서 잘못된 결과가 나오기도 한다
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000;
int N, E;
int specVertex1, specVertex2;
vector<int> dist;
vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>> pq;

inline int min(int a, int b) { return a < b ? a : b; }

using namespace std;

int dijkstra(int src, int dest) {
	pq = priority_queue<pair<int, int>>();
	dist = vector<int>(N + 1, INF);

	dist[src] = 0;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(nextDist, there));
			}
		}
	}

	return dist[dest];
}

int main() {
	
	cin >> N >> E;

	adj = vector<vector<pair<int, int>>>(N + 1);

	for (int i = 1; i <= E; i++) {
		//a번 정점에서 b번 정점까지 양방향 길이 존재하며
		//그 거리가 c라는 뜻이다.
		int a, b, c;

		cin >> a >> b >> c;

		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}

	cin >> specVertex1 >> specVertex2;

	long long Answer = min(dijkstra(1, specVertex1) + dijkstra(specVertex1, specVertex2) + dijkstra(specVertex2, N),
		dijkstra(1, specVertex2) + dijkstra(specVertex2, specVertex1) + dijkstra(specVertex1, N));

	if (Answer < INF) cout << Answer;
	else cout << "-1";
}