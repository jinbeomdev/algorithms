//2252번: 줄 세우기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;

void topological_sort(int vertex) {
	visited[vertex] = 1;

	for (int i = 0; i < adj[vertex].size(); i++) {
		if (!visited[adj[vertex][i]])
			topological_sort(adj[vertex][i]);
	}

	order.push_back(vertex);
}

int main() {	
	cin >> N >> M;

	adj = vector<vector<int>>(N + 1);
	visited = vector<bool>(N + 1, 0);

	for (int i = 1; i <= M; i++) {
		int A, B;

		cin >> A >> B;

		adj[A].push_back(B);
	}
	
	for (int i = 1; i <= N; i++) {
		if (!visited[i])
			topological_sort(i);
	}

	reverse(order.begin(), order.end());

	for (int i = 0; i < order.size(); i++) {
		cout << order[i] << " ";
	}
}