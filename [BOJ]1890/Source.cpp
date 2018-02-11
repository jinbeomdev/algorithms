//https://www.acmicpc.net/problem/1890

/*
����
N��N �����ǿ� ���� ������ �ִ�. �� ������ ��ǥ�� ���� ���� �� ĭ���� ���� ������ �Ʒ� ĭ���� ��Ģ�� �°� ������ �ؼ� ���� ���̴�.

�� ĭ�� �����ִ� ���� ���� ĭ���� �� �� �ִ� �Ÿ��� �ǹ��Ѵ�. �ݵ�� �������̳� �Ʒ������θ� �̵��ؾ� �Ѵ�. 0�� �� �̻� ������ ���� �������̸�, �׻� ���� ĭ�� �����ִ� ����ŭ �������̳� �Ʒ��� ���� �Ѵ�.

���� ���� �� ĭ���� ���� ������ �Ʒ� ĭ���� ��Ģ�� �°� �̵��� �� �ִ� ����� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� ũ�� N (4 �� N �� 100)�� �־�����. �� ���� N�� �ٿ��� �� ĭ�� ������ �ִ� ���� N���� �־�����. ĭ�� �����ִ� ���� 0���� ũ�ų� ����, 9���� �۰ų� ���� �����̸�, ���� ������ �Ʒ� ĭ���� �׻� 0�� �־�����.

���
���� ���� �� ĭ���� ���� ������ �Ʒ� ĭ���� ������ ��Ģ�� �°� �� �� �ִ� ����� ������ ����Ѵ�. ����� ������ 263-1���� �۰ų� ����.

���� �Է�  ����
4
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0
*/

#include <iostream>
#include <cstring>

using namespace std;

long long dfs(const int board[][100], long long dp[][100],
	const int i, const int j, const int N) {
	if (i == N - 1 && j == N - 1) {
		return 1;
	}

	long long &ret = dp[i][j];

	if (ret != -1) return ret;

	ret = 0;

	int to_down = i + board[i][j];
	int to_right = j + board[i][j];

	if (to_down < N) {
		dp[i][j] += dfs(board, dp, to_down, j, N);
	}

	if (to_right < N) {
		dp[i][j] += dfs(board, dp, i, to_right, N);
	}

	return dp[i][j];
}

int main() {
	int board[100][100];
	int N;
	long long dp[100][100];

	memset(dp, -1, sizeof(dp));

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}	
	
	cout << dfs(board, dp, 0, 0, N);
	
	//for debug
	//
	//dfs(board, dp, 0, 0, N);
	//for (int i = 0; i < N; i++, cout << endl) {
	//	for (int j = 0; j < N; j++) {
	//		cout << dp[i][j] << " ";
	//	}
	//}
	
	//system("pause");
}