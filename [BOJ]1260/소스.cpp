/*
https://www.acmicpc.net/problem/1260

DFS�� BFS Ǯ��
������
�ð� ����	�޸� ����	����	����	���� ���	���� ����
5 ��	128 MB	27304	8535	5144	29.460%
����
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�.

�Է�
ù° �ٿ� ������ ���� N(1��N��1,000), ������ ���� M(1��M��10,000), Ž���� ������ ������ ��ȣ V�� �־�����. ���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. �� ������ ���� �� �־��� ���� �ִµ�, ������ �ϳ��� �ִ� ������ �����ϸ� �ȴ�. �Է����� �־����� ������ ������̴�.

���
ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. V���� �湮�� ���� ������� ����ϸ� �ȴ�.

���� �Է�  ����
4 5 1
1 2
1 3
1 4
2 4
3 4
���� ���  ����
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