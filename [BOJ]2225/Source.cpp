//https://www.acmicpc.net/problem/2225

/*
����
0���� N������ ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

������ ������ �ٲ� ���� �ٸ� ���� ����(1+2�� 2+1�� ���� �ٸ� ���). ���� �� ���� ���� ���� �� �� ���� �ִ�.

�Է�
ù° �ٿ� �� ���� N(1��N��200), K(1��K��200)�� �־�����.

���
ù° �ٿ� ���� 1,000,000,000���� ���� �������� ����Ѵ�.

���� �Է�
20 2
���� ���
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