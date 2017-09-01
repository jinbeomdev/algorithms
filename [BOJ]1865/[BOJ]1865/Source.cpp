//1865��: ��Ȧ
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int main() {
	int T, test_case;
	//N(1��N��500), ������ ���� M(1��M��2500), ��Ȧ�� ����(1��W��200)
	int N, M, W;
	// S�� E�� ����� ������ ��ȣ, T�� �� ���θ� ���� �̵��ϴµ� �ɸ��� �ð�
	int S, E, t;
	//first�� ����� ����, second�� ����ġ
	vector<vector<pair<int, int>>> adj;
	//dist[x][y] x�� ���������� �ؼ� y���� ���µ� �ּҰ���� ��
	vector<vector<int>> dist;
	//first�� cost, second�� ����
	priority_queue<pair<pair<int, int>, int>> pq;
	vector<int> upper;
	bool updated;
	

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		cin >> N >> M >> W;

		adj = vector<vector<pair<int, int>>>(N + 1);
		upper = vector<int>(N + 1, INF);

		//(�� ���δ� ������ ������ ��Ȧ�� ������ �ִ�.)
		//���� �Է�
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> t;
			
			adj[S].push_back(make_pair(E, t));
			adj[E].push_back(make_pair(S, t));
		}

		//��Ȧ �Է�
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