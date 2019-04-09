#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int T, N;
int S[16][16];
int answer;

vector<int> a;
vector<int> b;

void dfs(int idx) {
	if (idx == N) {
		if (a.size() != N / 2) return;
		if (b.size() != N / 2) return;

		int a_sum = 0;
		for (int i = 0; i < a.size(); i++) {
			for (int j = i + 1; j < a.size(); j++) {
				a_sum += S[a[i]][a[j]] + S[a[j]][a[i]];
			}
		}

		int b_sum = 0;
		for (int i = 0; i < b.size(); i++) {
			for (int j = i + 1; j < b.size(); j++) {
				b_sum += S[b[i]][b[j]] + S[b[j]][b[i]];
			}
		}

		int ret = abs(a_sum - b_sum);

		if (answer > ret) answer = ret;

		return;
	}

	a.push_back(idx);
	dfs(idx + 1);
	a.pop_back();

	b.push_back(idx);
	dfs(idx + 1);
	b.pop_back();
}

int main() {
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &S[i][j]);
			}
		}


		answer = 1e9;

		dfs(0);

		printf("#%d %d\n", tc, answer);
	}
}