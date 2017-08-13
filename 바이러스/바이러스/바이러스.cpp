#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	//컴퓨터의 개수
	int N;
	//엣지의 개수
	int E;
	vector<vector<int>> adj;
	vector<bool> selected;
	queue<int> q;
	int Answer = -1;

	cin >> N;
	cin >> E;

	adj = vector<vector<int>>(N + 1);
	selected = vector<bool>(N + 1, 0);

	for (int i = 0; i < E; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	} 

	q.push(1);

	while (!q.empty()) {
		int vertex = q.front();
		q.pop();

		if (selected[vertex])
			continue;

		selected[vertex] = 1;

		for (int i = 0; i < adj[vertex].size(); i++) {
			if (!selected[adj[vertex][i]]) {
				q.push(adj[vertex][i]);
			}
		}

		Answer++;
	}

	cout << Answer;
}