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
	//N : 컴퓨터의 개수 M : 간선의 개수
	int N, M, minimum_cost = 0;
	//간선의 목록
	vector<pair<int, pair<int, int>>> edges;

	cin >> N;
	cin >> M;

	edges = vector<pair<int, pair<int, int>>>(M);

	/*첫째 줄에 컴퓨터의 수(1 <= N <= 1000)가 주어진다.
	둘째 줄에는 연결할 수 있는 선의 수(1 <= M <= 100, 000)가 주어진다.
	셋째 줄부터 M + 2번째 줄까지 총 M개의 줄에 각 컴퓨터를 연결하는데 드는 비용이 주어진다.
	이 비용의 정보는 세 개의 정수로 주어지는데,
	만약에 a b c 가 주어져 있다고 하면
	a컴퓨터와 b컴퓨터를 연결하는데 비용이 c만큼 든다는 것을 의미한다. */
	for (int i = 0; i < M; i++) {
		int a, b, c;
		
		cin >> a >> b >> c;

		edges[i] = make_pair(c, make_pair(a - 1, b - 1));
	}

	//주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선의 목록을 selected에
	//저장하고, 가중치의 합을 계산한다.
	//가중치 순으로 정렬
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