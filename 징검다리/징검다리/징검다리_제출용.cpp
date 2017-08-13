#include <iostream>
#include <vector>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	//cin >> T;
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, K, L;
		vector<vector<int>> dp;
		vector<int> mines;
		vector<int> sum;

		//cin >> N >> K >> L;
		scanf("%d %d %d", &N, &K, &L);

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

				//cin >> mine;
				scanf("%d", &mine);

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

		cout << "Case #" << test_case + 1 << endl;
		cout << sum[N] << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}