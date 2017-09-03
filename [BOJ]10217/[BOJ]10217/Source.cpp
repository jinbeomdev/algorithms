//10217번: KCM Travel
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int main() {
	int T, test_case;
	int N, M, K;
	int u, v, c, d;
	vector<vector<pair<int, pair<int, int>>>> adj;
	priority_queue<pair<int, pair<int,int>>> pq;
	//dp[i][j] vertex i까지 오는데 사용한 j비용일때 최소 거리
	vector<vector<int>> dp;
	

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		cin >> N >> M >> K;

		adj = vector<vector<pair<int, pair<int, int>>>>(N + 1);
		dp = vector<vector<int>>(N + 1, vector<int>(M + 1, INF));

		for (int i = 0; i < K; i++) {
			cin >> u >> v >> c >> d;

			adj[u].push_back(make_pair(v, make_pair(c, d)));
		}

		pq.push(make_pair(0, make_pair(0, 1)));
		dp[1][0] = 0;

		while (!pq.empty()) {
			int dist = -pq.top().first;
			int cost = pq.top().second.first;
			int here = pq.top().second.second;
			pq.pop();

			if (dp[here][cost] < dist) continue;

			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int nextCost = cost + adj[here][i].second.first;
				int nextDist = dist + adj[here][i].second.second;

				if (nextCost > M) continue;
				else if (dp[there][nextCost] > nextDist) {
					dp[there][nextCost] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(nextCost, there)));
				}
			}
		}

		int answer = INF;
		for (int i = 0; i < M + 1; i++) {
			if (dp[N][i] < answer) answer = dp[N][i];
		}
		
		if (answer < INF) cout << answer << endl;
		else cout << "Poor KCM" << endl;
	}
}