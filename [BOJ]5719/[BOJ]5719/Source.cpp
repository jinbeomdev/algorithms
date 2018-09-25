#include <stdio.h>
#include <string.h>

#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX = 500;
const int INF = 1e9;

int N, M;
int S, D;
int U, V, P;
int adj[MAX][MAX];
int dist[MAX];

void dijkstra() {
	fill(dist, dist + MAX, INF);

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(S, 0));
	dist[S] = 0;
	
	while (!pq.empty()) {
		int here = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int next = 0; next < N; next++) {
			if (adj[here][next] == -1) continue;
			
			int next_cost = adj[here][next];

			if (dist[next] > cost + next_cost) {
				dist[next] = cost + next_cost;
				pq.push(make_pair(next, -(cost + next_cost)));
			}
		}
	}
}

void erase() {
	queue<int> q;
	q.push(D);

	while (!q.empty()) {
		int next = q.front();
		q.pop();
		
		for (int here = 0; here < N; here++) {
			if (adj[here][next] == -1) continue;

			if (dist[next] == dist[here] + adj[here][next]) {
				adj[here][next] = -1;
				q.push(here);
			}
		}
	}
}

int main() {
	while (true) {
		memset(adj, -1, sizeof(adj));

		scanf("%d%d", &N, &M);

		if (N == 0 && M == 0) {
			break;
		}

		scanf("%d%d", &S, &D);

		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &U, &V, &P);
			adj[U][V] = P;
		}

		dijkstra();
		erase();
		dijkstra();

		if (dist[D] == INF) {
			printf("-1\n");
		} else {
			printf("%d\n", dist[D]);
		}
	}
}