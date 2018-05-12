/* https://www.acmicpc.net/problem/11401 */

//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

const int kMaxK = 40000000;
const int kMod = 1000000007;

int dp[2][kMaxK] = { -1, };

int main() {
	int n, k;
	scanf("%d %d", &n, &k);


	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k && j <= i; j++) {
			if (j == 0 || i == j) {
				dp[1][j] = 1;
			} else {
				dp[1][j] = ((dp[0][j - 1]) % kMod + (dp[0][j] % kMod)) % kMod;
			}
		}

		for (int j = 0; j <= k && j <= i; j++) {
			dp[0][j] = dp[1][j];
		}
	}

	printf("%d", dp[0][k]);

	//system("pause");
}