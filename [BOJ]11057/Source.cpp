//https://www.acmicpc.net/problem/11057

/*
문제
오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이 때, 인접한 수가 같아도 오름차순으로 친다.

예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.

수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.

입력
첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.

출력
첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.

예제 입력  복사
1
예제 출력  복사
10
예제 입력 2  복사
2
예제 출력 2  복사
55
예제 입력 3  복사
3
예제 출력 3  복사
220
*/
#include <iostream>
#include <cstring>

using namespace std;

const int mod = 10007;

int main() {
	int N;
	int dp[1001][10];

	memset(dp, 0, sizeof(dp));

	cin >> N;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 10; i++) {
		answer = (answer + dp[N][i]) % mod;
	}

	cout << answer;

}