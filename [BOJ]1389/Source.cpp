#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int A, B;
vector<vector<int>> adj;
vector<pair<int, int>> answer; //ÄÉºó º£ÀÌÄÁ, ÀÎµ¦½º

bool Comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}

	return a.first < b.first;
}

int main() {
	scanf("%d%d", &N, &M);

	adj.resize(N);
	answer.resize(N);
	

	for (int i = 0; i < M; i++) {
		scanf("%d%d", &A, &B);
		A--, B--; //ÀÎµ¦½º Á¶Á¤

		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	for (int i = 0; i < N; i++) {
		queue<int> q;
		vector<bool> visited;
		int depth = 0;
		int kevin_bacon = 0;

		visited.resize(N, false);

		q.push(i);
		visited[i] = true;

		while (!q.empty()) {
			int q_size = q.size();

			for (int j = 0; j < q_size; j++) {
				int here = q.front();
				q.pop();

				for (int k = 0; k < adj[here].size(); k++) {
					int next = adj[here][k];

					if (!visited[next]) {
						visited[next] = true;
						q.push(next);
					}
				}
			}

			depth++;
			kevin_bacon += depth * q_size;
		}

		answer[i] = make_pair(kevin_bacon, i + 1);
	}

	sort(answer.begin(), answer.end());

	printf("%d", answer[0].second);

	return 0;
}