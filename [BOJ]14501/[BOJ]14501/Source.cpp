#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int T[15];
	int P[15];
	int dp[16] = {0, };
	int N;
	int MAX = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int t, p;
		scanf("%d%d", &t, &p);

		T[i] = t;
		P[i] = p;
	}

	for (int i = 0; i < N; i++) {
		if(i + T[i] <= N)
			dp[i + T[i]] = max(dp[i + T[i]], max(MAX,dp[i]) + P[i]);

		if (MAX < dp[i]) MAX = dp[i];
	}

	int ret = 0;
	for (int i = 0; i <= N; i++) {
		if (ret < dp[i]) ret = dp[i];
	}
	printf("%d", ret);
}