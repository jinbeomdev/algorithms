//11657번: 타임머신
#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

int main() {
	int N, M;
	vector<vector<pair<int, int>>> adj;
	vector<int> upper;
	bool updated;

	cin >> N >> M;

	adj = vector<vector<pair<int, int>>>(N + 1);
	upper = vector<int>(N + 1, INF);
	upper[1] = 0;

	for (int i = 0; i < M; i++) {
		int A, B, C;

		cin >> A >> B >> C;

		adj[A].push_back(make_pair(B, C));
	}

	for (int iter = 0; iter < N; iter++) {
		updated = false;

		for (int here = 1; here < N + 1; here++) {
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;

				if (upper[there] > upper[here] + adj[here][i].second) {
					upper[there] = upper[here] + adj[here][i].second;
					updated = true;
				}
			}
		}

		if (!updated) break;
	}

	if (updated) cout << "-1" << endl;
	else {
		for (int i = 2; i < N + 1; i++) {
			cout << ((upper[i] < INF) ? upper[i] : -1) << endl;
		}
	}
	
}