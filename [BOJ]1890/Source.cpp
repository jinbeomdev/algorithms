//https://www.acmicpc.net/problem/1890

/*
문제
N×N 게임판에 수가 적혀져 있다. 이 게임의 목표는 가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 점프를 해서 가는 것이다.

각 칸에 적혀있는 수는 현재 칸에서 갈 수 있는 거리를 의미한다. 반드시 오른쪽이나 아래쪽으로만 이동해야 한다. 0은 더 이상 진행을 막는 종착점이며, 항상 현재 칸에 적혀있는 수만큼 오른쪽이나 아래로 가야 한다.

가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 이동할 수 있는 경로의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 게임 판의 크기 N (4 ≤ N ≤ 100)이 주어진다. 그 다음 N개 줄에는 각 칸에 적혀져 있는 수가 N개씩 주어진다. 칸에 적혀있는 수는 0보다 크거나 같고, 9보다 작거나 같은 정수이며, 가장 오른쪽 아래 칸에는 항상 0이 주어진다.

출력
가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 문제의 규칙에 맞게 갈 수 있는 경로의 개수를 출력한다. 경로의 개수는 263-1보다 작거나 같다.

예제 입력  복사
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