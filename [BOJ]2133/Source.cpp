//https://www.acmicpc.net/problem/2133

/*
����
3��N ũ���� ���� 2��1, 1��2 ũ���� Ÿ�Ϸ� ä��� ����� ���� ���غ���.

�Է�
ù° �ٿ� N(1 �� N �� 30)�� �־�����.

���
ù° �ٿ� ����� ���� ����Ѵ�.

���� �Է�  ����
2
���� ���  ����
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