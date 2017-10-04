//��׸� ���� (Hungry Bird)

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> grid;
vector<vector<int>> dp;
vector<vector<bool>> visited;

const int X[] = { 0, 1, 0 };
const int Y[] = { 1, 0, -1 };

//���� ���� 2�� �̻� �ݺ� ������ �ʴ´�.
//�� �� �̻� ������ �������ϴ� ������ ������ �ʴ´�.
int solution(int direction, int x, int y) {
	if (x == N - 1 && y == 0) {
		return ((grid[x][y] == 'B') ? 1 : 0);
	}

	visited[x][y] = true;

	int& ret = dp[x][y];

	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < 3; i++) {
		int nextX = x + X[i];
		int nextY = y + Y[i];

		if (nextX >= 0 && nextX < N &&
			nextY >= 0 && nextY < N &&
			visited[y][x] == false) {

			//�������� �߿� �ٽ� ���� �ö� �� ����
			if (direction == 1, i == 0) continue;

			//���� ���� �������� �����ϸ� direction�� �ٲ���
			if (i == 3) {
				solution(1, nextX, nextY);
			}
			else {
				solution(direction, nextX, nextY);
			}
		}
	}

}

int main() {
	int T, test_case;

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {


		cin >> N;

		grid = vector<vector<char>>(N, vector<char>(N));
		dp = vector<vector<int>>(N, vector<int>(N, -1));
		visited = vector<vector<bool>>(N, vector<bool>(N, false));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> grid[i][j];
			}
		}
	}
}