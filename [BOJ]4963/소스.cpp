/*
https://www.acmicpc.net/problem/4963

문제
정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.



한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다.

두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. 지도는 바다로 둘러쌓여 있으며, 지도 밖으로 나갈 수 없다.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. w와 h는 50보다 작거나 같은 양의 정수이다.

둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각 테스트 케이스에 대해서, 섬의 개수를 출력한다.

예제 입력  복사
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0
예제 출력  복사
0
1
1
3
1
9
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;
int w, h;

const int DIR_RANGE = 8;
const int X_DIR[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int Y_DIR[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

const bool is_out_of_range(int x, int y) {
	if (x >= 0 && x < w &&
		y >= 0 && y < h) {
		return true;
	}

	return false;
}

void dfs(int x, int y) {
	visited[y][x] = true;

	for(int i = 0; i < DIR_RANGE; i++) {
			int next_y = y + Y_DIR[i];
			int next_x = x + X_DIR[i];
			if (is_out_of_range(next_x, next_y) &&
				visited[next_y][next_x] == false &&
				map[next_y][next_x] == 1) { //land
				dfs(next_x, next_y);
			}
	}
}

int main() {

	while (true) {
		int land = 0;

		cin >> w >> h;

		if (w == 0 && h == 0) {
			return 0;
		}

		map = vector<vector<int>>(h, vector<int>(w));
		visited = vector<vector<bool>>(h, vector<bool>(w, false));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] == false &&
					map[i][j] == 1) {
					dfs(j, i);
					land++;
				}
			}
		}

		cout << land << endl;
	}

	return 0;
}