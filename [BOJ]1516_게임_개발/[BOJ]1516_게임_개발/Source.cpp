//1516번: 게임 개발
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> buildTime;
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
	cin >> N;

	buildTime = vector<int>(N + 1);
	adj = vector<vector<int>>(N + 1);

	for (int i = 1; i < N + 1; i++) {
		int vertex;

		cin >> buildTime[i];

		while (true) {
			cin >> vertex;

			if (vertex == -1) break;

			adj[i].push_back(vertex);
		}
	}

	for (int i = 1; i < N + 1; i++) {
		int result = 0;
		visited = vector<bool>(N + 1);
		order.clear();

		topological_sort(i);

		for (int j = 0; j < order.size(); j++) {
			result += buildTime[order[j]];
		}

		cout << result << endl;
	}
}