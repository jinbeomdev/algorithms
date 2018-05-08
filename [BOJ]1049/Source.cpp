/* https://www.acmicpc.net/problem/1049 */
//#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int kInf = 10e8;

int main() {
	int n, m;
	int min_package_price = kInf, min_price = kInf;
	int dp[101];

	fill(dp, dp + 101, kInf);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;

		scanf("%d %d", &a, &b);
		
		min_package_price = min(min_package_price, a);
		min_price = min(min_price, b);
	}

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + min_price;

		for (int j = 1; j <= 6; j++) {
			if (i - j < 0) break;

			dp[i] = min(dp[i], dp[i - j] + min_package_price);
		}
	}

	printf("%d" , dp[n]);

	//system("pause");
}