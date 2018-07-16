#include <cstdio>
#include <queue>

using namespace std;

int main() {
	priority_queue<int> pq;
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int oper;

		scanf("%d", &oper);

		if (oper > 0) {
			pq.push(-oper);
		} else if (pq.empty()) {
			printf("%d\n", 0);
		} else {
			printf("%d\n", -pq.top());
			pq.pop();
		}
	}
}