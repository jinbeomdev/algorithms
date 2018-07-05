#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N, M;
int A, B;
vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> answer;

bool Comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}

	return a.first > b.first;
}

int dfs(int computer) {
	int num_visit = 1;

	for (int i = 0; i < adj[computer].size(); i++) {
		int next_computer = adj[computer][i];
		if (!visited[next_computer]) {
			visited[next_computer] = true;
			num_visit += dfs(next_computer);
		}
	}

	return num_visit;
}

int main() {
	scanf("%d%d", &N, &M);


	adj.resize(N);
	visited.resize(N, false);
	answer.resize(N);

	for (int i = 0; i < M; i++) {
		scanf("%d%d", &A, &B);
		A--; B--; //인덱스 0부터 시작하도록 맞추는 작업

		adj[B].push_back(A);
	}

	for (int i = 0; i < N; i++) {
		visited.clear();
		visited.resize(N, false);
		answer[i] = make_pair(dfs(i), i + 1);
	}

	sort(answer.begin(), answer.end(), Comp);

	printf("%d ", answer[0].second);

	for (int i = 1; answer.size(); i++) {
		if (answer[i].first == answer[0].first) {
			printf("%d ", answer[i].second);
		} else {
			break;
		}
	}

	return 0;
}