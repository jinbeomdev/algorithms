//https://www.acmicpc.net/problem/2133

/*
문제
3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

입력
첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

출력
첫째 줄에 경우의 수를 출력한다.

예제 입력  복사
2
예제 출력  복사
3
*/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int N;
	int dp[31];
	
	memset(dp, 0, sizeof(dp));

	cin >> N;

	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= 30; i+=2) {
			dp[i] += dp[i - 2] * 3;
			for (int j = i - 4; j >= 0; j -= 2) {
				dp[i] += dp[j] * 2;
			}
	}

	cout << dp[N];
}