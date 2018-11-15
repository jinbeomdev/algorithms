/*
* DFS로 연결성을 확인한 후 (visited 함수로 확인 가능)
*/

#include <stdio.h>

int N, M;
const int maxSize = 201;
int adj[maxSize][maxSize] = {};
bool visited[maxSize] = {};

void dfs(int here) {
	visited[here] = true;

	for (int next = 0; next < N; next++) {
		if (adj[here][next] && !visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	int startPoint;
	scanf("%d", &startPoint);

	dfs(startPoint - 1);

	for (int i = 1; i < M; i++) {
		int city;
		scanf("%d", &city);

		if (!visited[city - 1]) {
			printf("NO");
			return 0;
		}
	}

	printf("YES");
	return 0;
}