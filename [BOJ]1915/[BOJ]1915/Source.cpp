#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[1000][1000];
int dp[1000][1000];

int main() {
	int n, m;

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		dp[i][0] = arr[i][0];
		answer = max(answer, dp[i][0]);
	}

	for (int j = 0; j < n; j++) {
		dp[0][j] = arr[0][j];
		answer = max(answer, dp[0][j]);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
				if (arr[i][j]) {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
					dp[i][j] = (sqrt(dp[i][j]) + 1) * (sqrt(dp[i][j]) + 1);
				} else {
					dp[i][j] = 0;
				}

				answer = max(answer, dp[i][j]);
		}
	}

	printf("%d", answer);
}