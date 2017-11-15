/*
https://www.acmicpc.net/problem/11726

문제
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

예제 입력  복사
2
예제 출력  복사
2
예제 입력 2  복사
9
예제 출력 2  복사
55
*/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n;
	int dp[1001];

	memset(dp, 0, sizeof(dp));

	cin >> n;

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}

	cout << dp[n];
}