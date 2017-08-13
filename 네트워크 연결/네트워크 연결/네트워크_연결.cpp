#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct DisjointSet {
private:
	vector<int> parent, rank;
public:
	DisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};

int main() {
	//N : ��ǻ���� ���� M : ������ ����
	int N, M, minimum_cost = 0;
	//������ ���
	vector<pair<int, pair<int, int>>> edges;

	cin >> N;
	cin >> M;

	edges = vector<pair<int, pair<int, int>>>(M);

	/*ù° �ٿ� ��ǻ���� ��(1 <= N <= 1000)�� �־�����.
	��° �ٿ��� ������ �� �ִ� ���� ��(1 <= M <= 100, 000)�� �־�����.
	��° �ٺ��� M + 2��° �ٱ��� �� M���� �ٿ� �� ��ǻ�͸� �����ϴµ� ��� ����� �־�����.
	�� ����� ������ �� ���� ������ �־����µ�,
	���࿡ a b c �� �־��� �ִٰ� �ϸ�
	a��ǻ�Ϳ� b��ǻ�͸� �����ϴµ� ����� c��ŭ ��ٴ� ���� �ǹ��Ѵ�. */
	for (int i = 0; i < M; i++) {
		int a, b, c;
		
		cin >> a >> b >> c;

		edges[i] = make_pair(c, make_pair(a - 1, b - 1));
	}

	//�־��� �׷����� ���� �ּ� ���д� Ʈ���� ���Ե� ������ ����� selected��
	//�����ϰ�, ����ġ�� ���� ����Ѵ�.
	//����ġ ������ ����
	sort(edges.begin(), edges.end());

	DisjointSet sets(N);
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if (sets.find(u) == sets.find(v)) continue;
		sets.merge(u, v);
		minimum_cost += cost;
	}

	cout << minimum_cost;
}