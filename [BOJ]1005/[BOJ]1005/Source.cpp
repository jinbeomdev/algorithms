#include <stdio.h>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N_MAX = 1000;

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, K, W;
		vector<int> adj[N_MAX];
		int time[N_MAX] = {};
		int indegree[N_MAX] = {};
		int total_time[N_MAX] = {};
		scanf("%d%d", &N, &K);
		for (int j = 0; j < N; j++) {
			scanf("%d", &time[j]);
		}
		for (int j = 0; j < K; j++) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			adj[x].push_back(y);
			indegree[y]++;
		}
		scanf("%d", &W);
		queue<int> q;
		for (int i = 0; i < N; i++) {
			if (indegree[i] == 0) {
				total_time[i] = time[i];
				q.push(i);
			}
		}

		for (int i = 0; i < N; i++) {
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); i++) {
				int next = adj[here][i];
				total_time[next] = max(total_time[next], total_time[here] + time[next]);
				if (--indegree[next] == 0) {
					q.push(next);
				}
			}
		}

		printf("%d\n", total_time[W - 1]);
	}
}