/*
https://www.acmicpc.net/problem/2294

����
n���� ������ ������ �ִ�. ������ ������ ��Ÿ���� ��ġ�� �ٸ���. �� �������� ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. �׷��鼭 ������ ������ �ּҰ� �ǵ��� �Ϸ��� �Ѵ�. (������ ������ ��� ����� �� �ִ�.)

�Է�
ù°�ٿ� n, k�� �־�����. (1 �� n �� 100, 1 �� k �� 10,000) ���� n���� �ٿ��� ������ ������ ��ġ�� �־�����.

���
ù°�ٿ� ����� ������ �ּ� ������ ����Ѵ�. �Ұ����� ��쿡�� -1�� ����Ѵ�.

���� �Է�  ����
3 15
1
5
12
���� ���  ����
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