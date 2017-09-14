#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
	//초기화
	int N, K;
	int bulbs[200];
	//dp[i][j]
	//i에서 j까지의 부분 수열에서 전구의 색을 바꾸는 횟수의 최소값
	int dp[200][200];

	//입력
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> bulbs[i];

	//알고리즘
	//대각 성분은 부분 수열의 크기가 1
	//부분 수열의 크기가 1일 때는 전구의 색을 바꿀 필요가 없음
	//대각 성분은 0으로 초기화
	for (int i = 0; i < N; i++) {
		dp[i][i] = 0;
	}

	for (int j = 1; j < N; j++) {
		for (int i = j - 1; i >= 0; i--) {
			dp[i][j] = INF;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (bulbs[k] != bulbs[j]));
			}
		}
	}

	cout << dp[0][N - 1];
}