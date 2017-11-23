/*
https://www.acmicpc.net/problem/1260

DFS와 BFS 풀이
문제집
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
5 초	128 MB	27304	8535	5144	29.460%
문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다.

입력
첫째 줄에 정점의 개수 N(1≤N≤1,000), 간선의 개수 M(1≤M≤10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 한 간선이 여러 번 주어질 수도 있는데, 간선이 하나만 있는 것으로 생각하면 된다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

예제 입력  복사
4 5 1
1 2
1 3
1 4
2 4
3 4
예제 출력  복사
1 2 4 3
1 2 3 4
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> adj;
vector<bool> visited;
queue<int> q;

void dfs(int vertex) {
	visited[vertex] = true;
	cout << vertex << ' ';

	for (int i = 0; i < adj[vertex].size(); i++) {
		int next_vertex = adj[vertex][i];

		if (visited[next_vertex] == false) {
			dfs(next_vertex);
		}
	}
}

int main() {
	cin >> N >> M >> V;

	adj = vector<vector<int>>(N + 1);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++) {
		int vertex_1, vertex_2;

		cin >> vertex_1 >> vertex_2;

		adj[vertex_1].push_back(vertex_2);
		adj[vertex_2].push_back(vertex_1);
		sort(adj[vertex_1].begin(), adj[vertex_1].end());
		sort(adj[vertex_2].begin(), adj[vertex_2].end());
	}

	//dfs
	dfs(V);
	cout << endl;

	//bfs
	visited = vector<bool>(N + 1, false);
	q.push(V);
	visited[V] = true;
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();

		cout << vertex << ' ';

		for (int i = 0; i < adj[vertex].size(); i++) {
			int next_vertex = adj[vertex][i];

			if (visited[next_vertex] == false) {
				q.push(next_vertex);
				visited[next_vertex] = true;
			}
		}
	}
}