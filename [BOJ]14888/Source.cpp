#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int num[100];
int op[4];
long long max_answer = -1e10;
long long min_answer = 1e10;

void dfs(int depth, long long result) {
	if (depth == N - 1) {
		max_answer = max(max_answer, result);
		min_answer = min(min_answer, result);
		return;
	}

	if (op[0] > 0) {
		op[0]--;
		dfs(depth + 1, result + num[depth + 1]);
		op[0]++;
	}

	if (op[1] > 0) {
		op[1]--;
		dfs(depth + 1, result - num[depth + 1]);
		op[1]++;
	}

	if (op[2] > 0) {
		op[2]--;
		dfs(depth + 1, result * num[depth + 1]);
		op[2]++;
	}

	if (op[3] > 0) {
		op[3]--;
		dfs(depth + 1, result / num[depth + 1]);
		op[3]++;
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	scanf("%d%d%d%d", &op[0], &op[1], &op[2], &op[3]);

	dfs(0, num[0]);

	printf("%d\n%d", max_answer, min_answer);
}