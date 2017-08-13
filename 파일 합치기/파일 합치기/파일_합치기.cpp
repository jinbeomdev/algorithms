//11066번
//파일 합치기
//https://www.acmicpc.net/problem/11066

#include <iostream>
#include <vector>

using namespace std;

#define INT_MAX       2147483647    // maximum (signed) int value

int main() {
	//테스트 케이스 개수
	int T;
	//소설을 구성하는 장의 개수
	int K;
	vector<int> chapters;
	vector<vector<int>> dp;
	vector<int> sum;
	
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> K;

		int size = K + 1;

		chapters = vector<int>(size);
		dp = vector<vector<int>>(size, vector<int>(size, INT_MAX));
		sum = vector<int>(size, 0);

		for (int i = 1; i < size; i++) {
			cin >> chapters[i];
			sum[i] = sum[i - 1] + chapters[i];
		}

		for (int i = 0; i < size; i++) {
			dp[i][i] = 0;
		}

		for (int r = 2; r < size; r++) {
			for (int i = 1; i <= size - r; i++) {
				int j = i + r - 1;
				for (int k = i; k <= j - 1; k++) {
					if (dp[i][j] > dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1])
						dp[i][j] = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
				}
			}
		}
		cout << dp[1][K] << endl;
	}
}