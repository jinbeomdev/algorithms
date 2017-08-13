#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> visited;
vector<int> Answer;

void dfs(int vertex) {
	visited[vertex] = 1;

	if (adj[vertex].empty()) {
		Answer.push_back(vertex);
		return;
	}

	for (int i = 0; i < adj[vertex].size(); i++) {
		int nextVertex = adj[vertex][i];

		if (!visited[nextVertex]) {
			dfs(nextVertex);
		}
	}
}

int main() {

	cin >> N >> M;

	adj = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int A, B;
		
		cin >> A >> B;

		adj[A].push_back(B);
	}

	for (int i = 1; i < N + 1; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	sort(Answer.begin(), Answer.end());

	for (vector<int>::iterator it = Answer.begin(); it < Answer.end(); it++) {
		cout << *it << " ";
	} cout << endl;
}