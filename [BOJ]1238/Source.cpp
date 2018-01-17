//https://www.acmicpc.net/problem/1238

/*
����
N���� ���ڷ� ���е� ������ ������ �� ���� �л��� ��� �ִ�.

��� �� �� N���� �л��� X (1 �� X �� N)�� ������ �𿩼� ��Ƽ�� ���̱�� �ߴ�. �� ���� ���̿��� �� M���� �ܹ��� ���ε��� �ְ� i��° ���� �����µ� Ti(1 �� Ti �� 100)�� �ð��� �Һ��Ѵ�.

������ �л����� ��Ƽ�� �����ϱ� ���� �ɾ�� �ٽ� �׵��� ������ ���ƿ;� �Ѵ�. ������ �� �л����� ���� �������� �ִ� �ð��� ���� ���⸦ ���Ѵ�.

�� ���ε��� �ܹ����̱� ������ �Ƹ� �׵��� ���� ���� ���� �ٸ����� �𸥴�. N���� �л��� �� ���� ���µ� ���� ���� �ð��� �Һ��ϴ� �л��� �������� ���Ͽ���.

�Է�
ù° �ٿ� N(1 <= N <= 1,000), M(1 <= M <= 10,000), X�� �������� ���еǾ� �Էµȴ�. �� ��° �ٺ��� M+1��° �ٱ��� i��° ������ ������, ����, �׸��� �� ���θ� �����µ� �ʿ��� �ҿ�ð� Ti�� ���´�.

��� �л����� ������ X�� ���� �ְ�, X���� ������ ���ƿ� �� �ִ� �����͸� �Է����� �־�����.

���
ù ��° �ٿ� N���� �л��� �� ���� ���µ� ���� ���� �ɸ��� �л��� �ҿ�ð��� ����Ѵ�.

���� �Է�  ����
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3
���� ���  ����
10
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 10e9;

int main() {
	int N, M, X;
	vector<vector<pair<int, long long int>>> adj;
	vector<vector<long long int>> dist;
	priority_queue<pair<int, long long int>> pq;

	cin >> N >> M >> X;

	adj = vector<vector<pair<int, long long int>>>(N + 1);
	dist = vector<vector<long long int>>(N + 1, vector<long long int>(N + 1, INF));

	for (int i = 0; i < M; i++) {
		int from, to, cost;

		cin >> from >> to >> cost;

		adj[from].push_back({ to, cost });
	}
	for (int i = 1; i <= N; i++) {		
		pq.push({ i, 0 });

		while(!pq.empty()) {
			int here = pq.top().first;
			long long int cost = -pq.top().second;
			pq.pop();

			if (dist[i][here] < cost) continue;

			for (int j = 0; j < adj[here].size(); j++) {
				int there = adj[here][j].first;
				long long int next_cost = cost + adj[here][j].second;

				if (dist[i][there] > next_cost) {
					dist[i][there] = next_cost;
					pq.push({ there, -next_cost });
				}
			}
		}
	}

	long long int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		if (answer < dist[i][X] + dist[X][i] &&
			dist[i][X] < INF && dist[X][i] < INF) {
			answer = dist[i][X] + dist[X][i];
		}
	}

	cout << answer;
}