#include <stdio.h>
#include <queue>
#include <string.h>
#include <stack>

using namespace std;

int discoverd[100001];

int d[] = { -1, 1, 2};

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	memset(discoverd, -1, sizeof(discoverd));
	queue<int> q;
	q.push(N);
	discoverd[N] = -1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		if (here == K) {
			int i = here;
			stack<int> s;
			while (true) {
				s.push(i);
				i = discoverd[i];
				if (i == -1) break;
			}
			printf("%d\n", s.size() - 1);
			int size = s.size();
			for (int i = 0; i < size - 1; i++) {
				printf("%d ", s.top());
				s.pop();
			}
			printf("%d", s.top());
			s.pop();
			break;
		}

		for (int i = 0; i < 3; i++) {
			int next = here;
			if (i == 2) {
				next *= d[i];
			} else {
				next += d[i];
			}
			
			if (next < 0 || next > 100000) continue;
			if (next == N || discoverd[next] != -1) continue;

			discoverd[next] = here;
			q.push(next);
		}
	}
}