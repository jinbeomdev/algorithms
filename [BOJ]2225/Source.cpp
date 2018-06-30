//https://www.acmicpc.net/problem/2225

/*
문제
0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.

덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.

입력
첫째 줄에 두 정수 N(1≤N≤200), K(1≤K≤200)가 주어진다.

출력
첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.

예제 입력
20 2
예제 출력
21
*/

#include <iostream>

using namespace std;

const int kMod = 10e9;

int dp[201][201] = {};

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][j - k] % kMod;
			}
		}
	}

	cout << dp[k][n]%kMod;

	system("pause");
}