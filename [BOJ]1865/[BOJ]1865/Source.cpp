//1865번: 웜홀
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int main() {
	int T, test_case;
	//N(1≤N≤500), 도로의 개수 M(1≤M≤2500), 웜홀의 개수(1≤W≤200)
	int N, M, W;
	// S와 E는 연결된 지점의 번호, T는 이 도로를 통해 이동하는데 걸리는 시간
	int S, E, t;
	//first는 연결된 정점, second는 가중치
	vector<vector<pair<int, int>>> adj;
	//dist[x][y] x를 시작점으로 해서 y까지 가는데 최소경로의 값
	vector<vector<int>> dist;
	//first는 cost, second는 정점
	priority_queue<pair<pair<int, int>, int>> pq;
	vector<int> upper;
	bool updated;
	

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		cin >> N >> M >> W;

		adj = vector<vector<pair<int, int>>>(N + 1);
		upper = vector<int>(N + 1, INF);

		//(단 도로는 방향이 없으며 웜홀은 방향이 있다.)
		//도로 입력
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> t;
			
			adj[S].push_back(make_pair(E, t));
			adj[E].push_back(make_pair(S, t));
		}

		//웜홀 입력
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> t;
			adj[S].push_back(make_pair(E, -t));
		}

		for (int iter = 0; iter < N; iter++) {
			updated = false;

			for (int here = 1; here < N + 1; here++) {
				for (int i = 0; i < adj[here].size(); i++) {
					int there = adj[here][i].first;
					int cost = adj[here][i].second;

					if (upper[there] > upper[here] + cost) {
						upper[there] = upper[here] + cost;
						updated = true;
					}
				}
			}

			if (!updated) break;
		}

		if (updated) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}