//문제
//수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
//
//예를 들어, 수열 A = { 10, 20, 10, 30, 20, 50 } 인 경우에 가장 긴 증가하는 부분 수열은 A = { 10, 20, 10, 30, 20, 50 } 이고, 길이는 4이다.
//
//입력
//첫째 줄에 수열 A의 크기 N(1 ≤ N ≤ 1, 000)이 주어진다.
//
//둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1, 000)
//
//출력
//첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
//
//예제 입력
//6
//10 20 10 30 20 50
//
//예제 출력
//4

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int answer = 1;
	int N;
	int dp[1000];
	int A[1000];

	cin >> N;

	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		if (dp[i] == 0) dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	cout << answer;
}