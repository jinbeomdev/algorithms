// https://www.acmicpc.net/problem/2316

/*
도시 왕복하기 풀이
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	1424	274	187	21.178%
문제
N개의 도시가 P개의 양방향 길로 연결되어 있다. 이석원은 1번 도시와 2번 도시 사이를 오가며 워해머를 한다. 성실한 이석원은 두 도시 사이를 최대한 많이 왔다 갔다 하려 하는데, 이 때 한 번 방문했던 도시(1, 2번 도시 제외)를 두 번 이상 방문하지 않으려 한다. 한 번 1번 도시와 2번 도시 사이를 오갈 때, 반드시 한 개 이상의 도시를 중간에 거쳐야 한다. 입력에는 1번 도시와 2번 도시를 연결하는 길은 없다.

입력
첫째 줄에 두 정수 N(3≤N≤400), P(1≤P≤10,000)이 주어진다. 다음 P개의 줄에는 각 길이 연결하는 서로 다른 두 도시의 번호가 주어진다.

출력
첫째 줄에 왔다 갔다 할 수 있는 최대 회수를 출력한다.

예제 입력
5 5
1 3
3 2
1 5
5 4
4 2
예제 출력
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