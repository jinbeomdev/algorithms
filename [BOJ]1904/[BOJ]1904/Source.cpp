#include <stdio.h>

const int MOD = 15746;
int dp[1000001];

int main() {
	int N;

	scanf("%d", &N); 

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;

	for (int i = 5; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	printf("%d", dp[N]);
}