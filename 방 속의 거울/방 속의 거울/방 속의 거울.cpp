#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Answer;
//행렬의 크기
int N;
//각 방안에 있는 거울의 정보를 저장할 N * N 행렬
vector<vector<int>> mirrors;
vector<vector<bool>> visited;

int X[] = { 0, 0, 1, -1 };
int Y[] = { 1, -1, 0, 0 };

int change_direction(int direction, int mirror) {
	// 0 = 아래, 1 = 위, 2 = 오른쪽, 3 = 왼쪽
	if (mirror == 1) {//좌측 하단으로 45도
		return 3 - direction;
	}
	else if (mirror == 2) {//우측 하단으로 45도
		return (direction + 2) % 4;
	}
	else {//거울이 없으면 그대로~
		return direction;
	}
}
void dfs(int y, int x, int direction) {
	//cout << "dfs is called : int y = " << y << " int x = " << x << " direction = " << direction << endl;
	int nextDirection;

	if (y < 0 || y >= N || x < 0 || x >= N) {
		return;
	}

	if (!visited[y][x] && mirrors[y][x]) {
		visited[y][x] = 1;
		Answer = Answer + 1;
		//cout << "Answer is added on " << y << "," << x << endl;
	}

	nextDirection = change_direction(direction, mirrors[y][x]);

	dfs(y + Y[nextDirection], x + X[nextDirection], nextDirection);
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		cin >> N;

		mirrors = vector<vector<int>>(N, vector<int>(N, 0));
		visited = vector<vector<bool>>(N, vector<bool>(N, 0));

		for (int i = 0; i < N; i++) {
			string s;

			cin >> s;

			for (int j = 0; j < N; j++) {
				mirrors[i][j] = s[j] - 48;
			}
		}

		dfs(0, 0, 2);

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}
	return 0;
}