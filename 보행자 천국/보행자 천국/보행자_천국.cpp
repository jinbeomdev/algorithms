#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int MOD = 20170805;
//dp[y][x][direction] 은 y,x까지 direction 방향으로 온 경로의 수
int dp[500][500][2];

int X[] = { 1, 0 };
int Y[] = { 0, 1 };

int dfs(int y, int x, int direction, int m, int n, vector<vector<int>> &city_map) {
	if (y == m - 1 && x == n - 1) return 1;

	if (dp[y][x][direction] != -1) return dp[y][x][direction];

	dp[y][x][direction] = 0;

	for (int nextDirection = 0; nextDirection < 2; nextDirection++) {
		int nextY = y + Y[nextDirection];
		int nextX = x + X[nextDirection];

		if (nextY < 0 || nextY >= m || nextX < 0 || nextX >= n) continue;

		if (city_map[y][x] == 1) return dp[y][x][direction];

		if (city_map[y][x] == 2 && direction == 0 && nextDirection == 1) continue;
		
		if (city_map[y][x] == 2 && direction == 1 && nextDirection == 0) continue;

		dp[y][x][direction] = (dp[y][x][direction] + dfs(nextY, nextX, nextDirection, m, n, city_map)) % MOD;
	}

	return dp[y][x][direction];
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	memset(dp, -1, sizeof(dp));

	dp[m - 1][n - 1][0] = 1;
	dp[m - 1][n - 1][1] = 1;

	dfs(0, 0, 0, m, n, city_map);

	return dp[0][0][0];
}