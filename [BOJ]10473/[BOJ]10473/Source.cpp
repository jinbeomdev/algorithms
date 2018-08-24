#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<double, int> P;
const double V = 5.0;

inline double GetDistance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int n;
double x[102];
double y[102];

int main() {
	scanf("%lf%lf%lf%lf%d", x, y, x + 1, y + 1, &n);
	
	for (int i = 2; i < n + 2; i++) {
		scanf("%lf%lf", x + i, y + i);
	}

	double dist[102] = { 0 };
	vector<vector<P>> adj(n + 2);
	dist[0] = 0;
	for (int i = 1; i < n + 2; i++) {
		dist[i] = -1;
		adj[0].push_back(P(GetDistance(x[0], y[0], x[i], y[i]) / V, i));
		if (i == 1) continue;
		adj[i].push_back(P(2.0 + abs(GetDistance(x[1], y[1], x[i], y[i]) - 50.0) / V, 1));
		for (int j = i + 1; j < n + 2; j++) {
			double t = 2.0 + abs(GetDistance(x[i], y[i], x[j], y[j]) - 50.0) / V;
			adj[i].push_back(P(t, j));
			adj[j].push_back(P(t, i));
		}
	}

	priority_queue<P> pq;
	pq.push(P(0, 0));
	bool visited[102] = { 0 };
	for (int i = 0; i < n + 2; i++) {
		int u;
		do {
			u = pq.top().second;
			pq.pop();
		} while (visited[u]);
		visited[u] = true;
		for (auto& edge : adj[u]) {
			if (dist[edge.second] < 0 || dist[edge.second] > dist[u] + edge.first) {
				dist[edge.second] = dist[u] + edge.first;
				pq.push(P(-dist[edge.second], edge.second));
			}
		}
	}
	printf("%.6lf\n", dist[1]);
}