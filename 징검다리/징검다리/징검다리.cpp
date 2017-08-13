#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K, L;
	vector<vector<int>> dp;
	vector<int> mines;
	vector<int> sum;

	cin >> N >> K >> L;

	dp = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	mines = vector<int>(L, 0);
	sum = vector<int>(N + 1, 0);

	for (int i = 0; i < N + 1; i++) {
		dp[i][i] = -1;
	}


	//지뢰 설치
	if (L != 0) {
		for (int i = 0; i < L; i++) {
			int mine;

			cin >> mine;

			for (int i = 0; i < mine; i++) {
				dp[i][mine] = -1;
			}
		}
	}

	//출발점에서 갈 수 있는 곳은 초기화를 해 놓음
	for (int i = 1; i <= K; i++) {
		//지뢰가 아닌 경우에만 갈 수 있도록 초기화
		if (dp[0][i] != -1) {
			dp[0][i] = 1;
			sum[i] = 1;
		}
	}

	//첫 번째 돌에서 갈 수있는 경우의 수 부터 채워넣기
	for (int i = 1; i < N + 1; i++) {
		for (int j = i + 1; j <= i + K && j < N + 1; j++) {
			if (i - (j - i) > 0) {
				dp[i][j] += sum[i] - dp[i - (j - i)][i];
			}
			else {
				dp[i][j] += sum[i];
			}

			sum[j] += dp[i][j];
		}
	}

	////정답은
	//for (int i = 0; i < N; i++) {
	//	Answer += dp[i][N];
	//}

	cout << sum[N] << endl;

	//for (int i = 0; i < N + 1; i++) {
	//	for (int j = 0; j < N + 1; j++) {
	//		cout << dp[i][j] << " ";
	//	} cout << endl;
	//}
}

