#include <cstdio>
	
int N, S, M;
int V[100];
bool dp[101][1001];

int main() {
	scanf("%d%d%d", &N, &S, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &V[i]);
	}

	if (S - V[0] >= 0) dp[1][S - V[0]] = true;
	if (S + V[0] <= M) dp[1][S + V[0]] = true;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j] == true) {
				if (j - V[i - 1] >= 0) dp[i][j - V[i - 1]] = true;
				if (j + V[i - 1] <= M) dp[i][j + V[i - 1]] = true;
			}
		}
	}

	int answer = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[N][i]) {
			answer = i;
		}
	}

	printf("%d", answer);
}