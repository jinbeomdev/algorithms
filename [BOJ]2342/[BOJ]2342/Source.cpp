//2342번 : Dance Dance Revolution
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321;

int calculate(int a, int b) {
	if (a == 0) return 2;
	else if (abs(a - b) == 2) return 4;
	else if (abs(a - b) == 1 || abs(a - b) == 3) return 3;
	return 1;
}

int main() {
	vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(100001, vector<vector<int>>(5, vector<int>(5, INF)));
	int cnt = 1;
	int n;

	dp[0][0][0] = 0;

	while (true) {
		cin >> n;
		
		if (n == 0) break;

		//오른발 움직이기
		for (int l = 0; l < 5; l++) {
			if (l == n) continue;
			for (int r = 0; r < 5; r++) {
				int power = calculate(r, n);
				dp[cnt][l][n] = min(dp[cnt][l][n], dp[cnt - 1][l][r] + power);
			}
		}

		//왼발 움직이기
		for (int r = 0; r < 5; r++) {
			if (r == n) continue;
			for (int l = 0; l < 5; l++) {
				int power = calculate(l, n);
				dp[cnt][n][r] = min(dp[cnt][n][r], dp[cnt - 1][l][r] + power);
			}
		}
		cnt++;
	}
	cnt--;
	int ans = 2 * INF;
	for (int l = 0; l < 5; l++) {
		for (int r = 0; r < 5; r++) {
			ans = min(ans, dp[cnt][l][r]);
		}
	}
	cout << ans;
}