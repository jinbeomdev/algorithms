#include <stdio.h>
#include <algorithm>

using namespace std;

int T;
int dp[12];
int days[12];
int day;
int oneMon;
int threeMon;
int year;

int main() {
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d%d%d%d", &day, &oneMon, &threeMon, &year);
		
		for (int i = 0; i < 12; i++) {
			scanf("%d", &days[i]);
			days[i] *= day;
			dp[i] = 1e9;
		}

		dp[0] = min(days[0], oneMon);
		dp[2] = threeMon;
		for (int i = 1; i < 12; i++) {
			dp[i] = min(dp[i], min(dp[i - 1] + days[i], dp[i - 1] + oneMon));

			if (i - 3 >= 0) dp[i] = min(dp[i], dp[i - 3] + threeMon);
		}
		dp[11] = min(dp[11], year);

		printf("#%d %d\n", tc, dp[11]);
	}
}