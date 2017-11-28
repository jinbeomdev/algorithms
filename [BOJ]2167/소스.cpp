/*
https://www.acmicpc.net/problem/2167

����
2���� �迭�� �־����� �� (i, j) ��ġ���� (x, y) ��ġ������ ����Ǿ� �ִ� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �迭�� (i, j) ��ġ�� i�� j���� ��Ÿ����.

�Է�
ù° �ٿ� �迭�� ũ�� N, M(1��N, M��300)�� �־�����. ���� N���� �ٿ��� M���� ������ �迭�� �־�����. �� ���� �ٿ��� ���� ���� �κ��� ���� K(1��K��10,000)�� �־�����. ���� K���� �ٿ��� �� ���� ������ i, j, x, y�� �־�����(i��x, j��y).

���
K���� �ٿ� ������� �迭�� ���� ����Ѵ�. �迭�� ���� 32bit-int ������ �ʰ����� �ʴ´�.

���� �Է�  ����
2 3
1 2 4
8 16 32
3
1 1 2 3
1 2 1 2
1 3 2 3
���� ���  ����
63
2
36
*/

#include <iostream>

using namespace std;

int main() {
	int N, M;
	int arr[301][301] = { 0, };
	int psum[301][301] = { 0, };
	int K;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];

			if (j == 1) {
				psum[i][j] = psum[i - 1][M] + arr[i][j];
			}
			else {
				psum[i][j] = psum[i][j - 1] + arr[i][j];
			}
		}
	}
	
	cin >> K;

	//for (int test_case = 0; test_case < K; test_case++) {
	//	int i, j, x, y;
	//	
	//	cin >> i >> j >> x >> y;

	//	if (j == 1) {
	//		cout << (psum[x][y] - psum[i - 1][M]) << endl;
	//	}
	//	else {
	//		cout << psum[x][y] - psum[i][y - 1] << endl;
	//	}
	//}

	for (int test_case = 0; test_case < K; test_case++) {
		int i, j, x, y;
		int sum = 0;

		cin >> i >> j >> x >> y;

		for (int row = i; row <= x; row++) {
			for (int col = j; col <= y; col++) {
				sum += arr[row][col];
			}
		}

		cout << sum << endl;
	}
}