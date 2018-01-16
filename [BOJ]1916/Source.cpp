//https://www.acmicpc.net/problem/1916

/*
����
n(1��n��1,000)���� ���ð� �ִ�. �׸��� �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� m(1��m��100,000)���� ������ �ִ�. �츮�� A��° ���ÿ��� B��° ���ñ��� ���µ� ��� ���� ����� �ּ�ȭ ��Ű���� �Ѵ�. �׷��� A��° ���ÿ��� B��° ���� ���� ���µ� ��� �ּҺ���� ����Ͽ���.

�Է�
ù° �ٿ� ������ ���� n(1��n��1,000)�� �־����� ��° �ٿ��� ������ ���� m(1��m��100,000)�� �־�����. �׸��� ��° �ٺ��� m+2�ٱ��� ������ ���� ������ ������ �־�����. ���� ó������ �� ������ ��� ������ ��ȣ�� �־�����. �׸��� �� �������� �������� ���� ��ȣ�� �־����� �� �� ���� ����� �־�����. ���� ����� 0���� ũ�ų� ����, 100,000���� ���� �����̴�.

�׸��� m+3° �ٿ��� �츮�� ���ϰ��� �ϴ� ���� ������� ���ù�ȣ�� �������� ���ù�ȣ�� �־�����. ��������� �������� �� �� �ִ� ��츸 �Է����� �־�����.

���
ù° �ٿ� ��� ���ÿ��� ���� ���ñ��� ���µ� ��� �ּ� ����� ����Ѵ�.

���� �Է�  ����
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5
���� ���  ����
4
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
const int INF = 1e9;

int main() {
	priority_queue<pair<int , long long int>> pq;
	vector<vector<pair<int, int>>> adj;
	vector<long long int> dist;
	int n, m;
	int start, destination;

	cin >> n >> m;

	adj = vector<vector<pair<int, int>>>(n + 1);
	dist = vector<long long int>(n + 1, INF);

	for (int i = 0; i < m; i++) {
		int from, to, cost;

		cin >> from >> to >> cost;

		adj[from].push_back({ to, cost });
	}

	cin >> start >> destination;
	
	pq.push({ start, 0 });
	while (!pq.empty()) {
		int here = pq.top().first;
		long long int cost = -pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int next_cost = cost + adj[here][i].second;

			if (dist[there] > next_cost) {
				dist[there] = next_cost;
				pq.push({ there, -next_cost });
			}
		}
	}

	cout << dist[destination];
}