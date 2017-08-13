#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K, L;
	vector<vector<int>> dp;
	vector<int> mines;
	vector<int> sum;

	cin >> N >> K >> L;

	dp = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	mines = vector<int>(L, 0);
	sum = vector<int>(N + 1, 0);

	for (int i = 0; i < N + 1; i++) {
		dp[i][i] = -1;
	}


	//���� ��ġ
	if (L != 0) {
		for (int i = 0; i < L; i++) {
			int mine;

			cin >> mine;

			for (int i = 0; i < mine; i++) {
				dp[i][mine] = -1;
			}
		}
	}

	//��������� �� �� �ִ� ���� �ʱ�ȭ�� �� ����
	for (int i = 1; i <= K; i++) {
		//���ڰ� �ƴ� ��쿡�� �� �� �ֵ��� �ʱ�ȭ
		if (dp[0][i] != -1) {
			dp[0][i] = 1;
			sum[i] = 1;
		}
	}

	//ù ��° ������ �� ���ִ� ����� �� ���� ä���ֱ�
	for (int i = 1; i < N + 1; i++) {
		for (int j = i + 1; j <= i + K && j < N + 1; j++) {
			if (i - (j - i) > 0) {
				dp[i][j] += sum[i] - dp[i - (j - i)][i];
			}
			else {
				dp[i][j] += sum[i];
			}

			sum[j] += dp[i][j];
		}
	}

	////������
	//for (int i = 0; i < N; i++) {
	//	Answer += dp[i][N];
	//}

	cout << sum[N] << endl;

	//for (int i = 0; i < N + 1; i++) {
	//	for (int j = 0; j < N + 1; j++) {
	//		cout << dp[i][j] << " ";
	//	} cout << endl;
	//}
}

