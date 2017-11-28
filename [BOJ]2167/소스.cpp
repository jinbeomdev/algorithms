/*
https://www.acmicpc.net/problem/2167

문제
2차원 배열이 주어졌을 때 (i, j) 위치부터 (x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 프로그램을 작성하시오. 배열의 (i, j) 위치는 i행 j열을 나타낸다.

입력
첫째 줄에 배열의 크기 N, M(1≤N, M≤300)이 주어진다. 다음 N개의 줄에는 M개의 정수로 배열이 주어진다. 그 다음 줄에는 합을 구할 부분의 개수 K(1≤K≤10,000)가 주어진다. 다음 K개의 줄에는 네 개의 정수로 i, j, x, y가 주어진다(i≤x, j≤y).

출력
K개의 줄에 순서대로 배열의 합을 출력한다. 배열의 합은 32bit-int 범위를 초과하지 않는다.

예제 입력  복사
2 3
1 2 4
8 16 32
3
1 1 2 3
1 2 1 2
1 3 2 3
예제 출력  복사
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