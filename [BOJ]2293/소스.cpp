/*
https://www.acmicpc.net/problem/2293

����
n���� ������ ������ �ִ�. ������ ������ ��Ÿ���� ��ġ�� �ٸ���. �� �������� ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. �� ����� ���� ���Ͻÿ�. (������ ������ �� ���� ����� �� �ִ�.)

�Է�
ù°�ٿ� n, k�� �־�����. (1 �� n �� 100, 1 �� k �� 10,000) ���� n���� �ٿ��� ������ ������ ��ġ�� �־�����.

���
ù° �ٿ� ����� ���� ����Ѵ�. ����� ���� 2^31���� �۴�.

���� �Է�  ����
3 10
1
2
5
���� ���  ����
10
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n, k;
	int dp[10001];
	int coins[100];

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - coins[i]]; 
		} 
	}

	cout << dp[k];
}