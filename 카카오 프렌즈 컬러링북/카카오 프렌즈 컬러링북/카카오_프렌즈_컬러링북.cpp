#include <vector>
#include <iostream>

using namespace std;

int X[] = { 0, 1, 0, -1 };
int Y[] = { -1, 0, 1, 0 };

vector<vector<bool>> visited;

inline int max(int a, int b) { return (((a) > (b)) ? (a) : (b)); }

int dfs(int y, int x, int m, int n, vector<vector<int>> &picture) {
	int number = 1;
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nextY = y + Y[i];
		int nextX = x + X[i];
		if (nextY >= 0 && nextY < m &&
			nextX >= 0 && nextX < n &&
			!visited[nextY][nextX] &&
			picture[y][x] == picture[nextY][nextX])
		{
			number += dfs(nextY, nextX, m , n, picture);
		}
	}

	return number;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int component_number = 0;
	int max_value = 0;

	visited = vector<vector<bool>>(m, vector<bool>(n, 0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && picture[i][j] > 0) {
				int temp = dfs(i, j, m, n, picture);
				max_value = max(max_value, temp);
				component_number = component_number + 1;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = component_number;
	answer[1] = max_value;

	return answer;
}

int main() {
	vector<vector<int>> picture = vector<vector<int>>(6, vector<int>(4, 0));

	picture[0] = { 1,1,1,0 };
	picture[1] = { 1,2,2,0 };
	picture[2] = { 1,0,0,1 };
	picture[3] = { 0,0,0,1 };
	picture[4] = { 0,0,0,3 };
	picture[5] = { 0,0,0,3 };


	vector<int> Answer = solution(6, 4, picture);

	cout << Answer[0] << " " << Answer[1] << endl;
}