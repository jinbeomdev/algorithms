#include <stdio.h>
#include <string.h>

long long dp[68];

long long koong(int n) {
	long long& ret = dp[n];

	if (dp[n] != -1ll) return ret;
	
	return dp[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
}

int main() {
	memset(dp, -1, sizeof(dp));

	int t;

	scanf("%d", &t);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", koong(n));
	}
}