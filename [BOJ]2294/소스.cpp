/*
https://www.acmicpc.net/problem/2294

문제
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. (각각의 동전은 몇개라도 사용할 수 있다.)

입력
첫째줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다.

출력
첫째줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.

예제 입력  복사
3 15
1
5
12
예제 출력  복사
3
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
	int n, k;
	int dp[10001];
	int coins[100];

	for (int i = 0; i < 10001; i++) {
		dp[i] = INF;
	}

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - coins[j] < 0) {
				continue;
			}

			dp[i] = min(dp[i], dp[i - coins[j]] + 1);
		}
	}

	if (dp[k] >= INF) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}
}