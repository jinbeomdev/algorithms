#include <stdio.h>
#include <queue>
#include <string.h>
#include <stack>

using namespace std;

int discoverd[10000];
int back[10000];
char int2char[] = { 'D', 'S', 'L', 'R' };

int oper(int i, int n) {
	if (n == 0) n = 9999;
	if (i == 0) {
		return (n * 2) % 10000;
	} else if (i == 1) {
		return ((n - 1) == 0) ? 9999 : n - 1;
	} else if (i == 2) {
		int d[4];
		for (int j = 0, k = 1000; j < 4; j++, k /= 10) {
			d[j] = n / k;
			n = n % k;
		}
		return d[1] * 1000 + d[2] * 100 + d[3] * 10 + d[0];
	} else {
		int d[4];
		for (int j = 0, k = 1000; j < 4; j++, k /= 10) {
			d[j] = n / k;
			n = n % k;
		}
		return d[3] * 1000 + d[0] * 100 + d[1] * 10 + d[2];
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int A, B;
		scanf("%d%d", &A, &B);
		memset(discoverd, -1, sizeof(discoverd));
		queue<int> q;
		q.push(A);
		while (!q.empty()) {
			int here = q.front();
			q.pop();

			if (here == B) {
				stack<char> s;
				int j = here;
				while (discoverd[j] != -1) {
					s.push(int2char[back[j]]);
					j = discoverd[j];
				}
				while (!s.empty()) {
					printf("%c", s.top());
					s.pop();
				}
				printf("\n");
				break;
			}

			for (int j = 0; j < 4; j++) {
				int next = oper(j, here);

				if (next == A) continue;
				if (discoverd[next] != -1) continue;

				q.push(next);
				discoverd[next] = here;
				back[next] = j;
			}
		}
	}
}