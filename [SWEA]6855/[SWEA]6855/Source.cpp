#include <stdio.h>
#include <algorithm>

using namespace std;

struct Edge {
	int u, v, w;
	Edge() : Edge(-1, -1, 0) {}
	Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
	bool operator < (const Edge &rhs) const { return w < rhs.w; }
};

Edge edge[100000];
int uf[100000];

int find(int a, int uf[]) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a], uf);
}

bool merge(int a, int b, int uf[]) {
	a = find(a, uf);
	b = find(b, uf);
	if (a == b) return false;
	uf[b] = a;
	return true;
}

int main() {
	int T, N, K;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d", &N, &K);
		int pre, cur;
		scanf("%d", &pre);
		for (int i = 1; i < N; i++) {
			scanf("%d", &cur);
			edge[i - 1] = Edge(i - 1, i, cur - pre);
			pre = cur;
		}
		if (N <= K) {
			printf("#%d 0\n", test_case);
			continue;
		}
		sort(edge, edge + N - 1);
		int result = 0, cnt = 0;
		fill(uf, uf + N, -1);
		for (int i = 0;; i++) {
			if (merge(edge[i].u, edge[i].v, uf)) {
				result += edge[i].w;
				if (++cnt == N - K) break;
			}
		}
		printf("#%d %d\n", test_case, result);
	}
}