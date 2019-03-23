#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int N;
int S[20][20];
vector<int> a;
vector<int> b;
int answer = 1e9;

void dfs(int idx, int num_a, int num_b) {
	if (num_a * 2 > N) {
		return;
	}

	if (num_b * 2 > N) {
		return;
	}

	if (idx == N) {
		int sum_a = 0, sum_b = 0;
		for (int i = 0; i < a.size(); i++) {
			for (int j = i + 1; j < a.size(); j++) {
				sum_a += S[a[i]][a[j]] + S[a[j]][a[i]];
			}
		}

		for (int i = 0; i < b.size(); i++) {
			for (int j = i + 1; j < b.size(); j++) {
				sum_b += S[b[i]][b[j]] + S[b[j]][b[i]];
			}
		}

		int ret = abs(sum_a - sum_b);

		if (answer > ret) answer = ret;
		return;
	}

	a.push_back(idx);
	dfs(idx + 1, num_a + 1, num_b);
	a.pop_back();

	b.push_back(idx);
	dfs(idx + 1, num_a, num_b + 1);
	b.pop_back();
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &S[i][j]);
		}
	}

	dfs(0, 0, 0);
	printf("%d", answer);
}