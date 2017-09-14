#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
	//�ʱ�ȭ
	int N, K;
	int bulbs[200];
	//dp[i][j]
	//i���� j������ �κ� �������� ������ ���� �ٲٴ� Ƚ���� �ּҰ�
	int dp[200][200];

	//�Է�
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> bulbs[i];

	//�˰���
	//�밢 ������ �κ� ������ ũ�Ⱑ 1
	//�κ� ������ ũ�Ⱑ 1�� ���� ������ ���� �ٲ� �ʿ䰡 ����
	//�밢 ������ 0���� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		dp[i][i] = 0;
	}

	for (int j = 1; j < N; j++) {
		for (int i = j - 1; i >= 0; i--) {
			dp[i][j] = INF;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (bulbs[k] != bulbs[j]));
			}
		}
	}

	cout << dp[0][N - 1];
}