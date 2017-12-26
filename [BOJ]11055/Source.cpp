//https://www.acmicpc.net/problem/11055

/*
문제
수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.

예제 입력  복사
10
1 100 2 50 60 3 5 6 7 8
예제 출력  복사
113
*/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int arr[1000];
	int dp[1000];
	int N;

	memset(arr, 0, sizeof(arr));

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[j] + arr[i] > dp[i]) {
					dp[i] = dp[j] + arr[i];
				}
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	cout << answer;
}