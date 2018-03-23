// https://www.acmicpc.net/problem/2316

/*
���� �պ��ϱ� Ǯ��
�ð� ����	�޸� ����	����	����	���� ���	���� ����
2 ��	128 MB	1424	274	187	21.178%
����
N���� ���ð� P���� ����� ��� ����Ǿ� �ִ�. �̼����� 1�� ���ÿ� 2�� ���� ���̸� ������ ���ظӸ� �Ѵ�. ������ �̼����� �� ���� ���̸� �ִ��� ���� �Դ� ���� �Ϸ� �ϴµ�, �� �� �� �� �湮�ߴ� ����(1, 2�� ���� ����)�� �� �� �̻� �湮���� ������ �Ѵ�. �� �� 1�� ���ÿ� 2�� ���� ���̸� ���� ��, �ݵ�� �� �� �̻��� ���ø� �߰��� ���ľ� �Ѵ�. �Է¿��� 1�� ���ÿ� 2�� ���ø� �����ϴ� ���� ����.

�Է�
ù° �ٿ� �� ���� N(3��N��400), P(1��P��10,000)�� �־�����. ���� P���� �ٿ��� �� ���� �����ϴ� ���� �ٸ� �� ������ ��ȣ�� �־�����.

���
ù° �ٿ� �Դ� ���� �� �� �ִ� �ִ� ȸ���� ����Ѵ�.

���� �Է�
5 5
1 3
3 2
1 5
5 4
4 2
���� ���
2
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 805;
const int INF = 10e9;

struct Edge {
	int to, c, f;
	Edge *dual;
	Edge() : Edge(-1, 0) {}
	Edge(int to1, int c1) : to(to1), c(c1), f(0), dual(nullptr) {}
	int spare() {
		return c - f;
	}
	void addFlow(int f1) {
		f += f1;
		dual->f -= f1;
	}
};

int main() {
	vector<Edge*> adj[MAX];
	int N, P;

	cin >> N >> P;

	for (int i = 0; i < N; i++) {
		int u = i * 2;
		int v = u + 1;

		Edge *e1 = new Edge(v, 1);
		Edge *e2 = new Edge(u, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	for (int i = 0; i < P; i++) {
		int u, v;

		cin >> u >> v;

		u--; v--;

		Edge *e1 = new Edge(v * 2, 1);
		Edge *inverse_e1 = new Edge(u * 2 + 1, 0);
		Edge *e2 = new Edge(u * 2, 1);
		Edge *inverse_e2 = new Edge(v * 2 + 1, 0);
		
		e1->dual = inverse_e1;
		inverse_e1->dual = e1;
		e2->dual = inverse_e2;
		inverse_e2->dual = e2;
		adj[u * 2 + 1].push_back(e1);
		adj[v * 2].push_back(inverse_e1);
		adj[v * 2 + 1].push_back(e2);
		adj[u * 2].push_back(inverse_e2);
	}

	int total = 0, S = 1, E = 2;
	while (true) {
		int prev[MAX];
		Edge *path[MAX] = { nullptr };
		queue<int> q;

		memset(prev, -1, sizeof(prev));
		
		q.push(S);
		
		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			for (Edge *e : adj[curr]) {
				int next = e->to;
			
				if(e->spare() > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = curr;
					path[next] = e;
					
					if (next == E) {
						break;
					}
				}
			}
		}

		if (prev[E] == -1) {
			break;
		}

		int flow = INF;

		for (int i = E; i != S; i = prev[i]) {
			flow = min(flow, path[i]->spare());
		}

		for (int i = E; i != S; i = prev[i]) {
			path[i]->addFlow(flow);
		}
		total += flow;
	}

	cout << total;

	//system("pause");
}