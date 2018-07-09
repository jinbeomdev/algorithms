#include <cstdio>
#include <vector>

using namespace std;

const int ROW_SIZE = 9;
const int COL_SIZE = 9;

int map[ROW_SIZE][COL_SIZE];

vector<pair<int, int>> blank_pos;

bool CheckRow(int idx, int num) {
	int y = blank_pos[idx].first;

	for (int i = 0; i < COL_SIZE; i++) {
		if (map[y][i] == 0) continue;
		if (map[y][i] == num) return false;
	}
	
	return true;
}

bool CheckCol(int idx, int num) {
	int x = blank_pos[idx].second;

	for (int i = 0; i < ROW_SIZE; i++) {
		if (map[i][x] == 0) continue;
		if (map[i][x] == num) return false;
	}

	return true;
}

bool CheckBox(int idx, int num) {
	int x = blank_pos[idx].second;
	int y = blank_pos[idx].first;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[y - (y % 3) + i][x - (x % 3) + j] == 0) continue;
			if (map[y - (y % 3) + i][x - (x % 3) + j] == num) return false;
		}
	}

	return true;
}

bool CheckRows() {
	for (int i = 0; i < ROW_SIZE; i++) {
		bool check[COL_SIZE] = { false, };

		for (int j = 0; j < COL_SIZE; j++) {
			if (check[map[i][j] - 1]) return false;
			check[map[i][j] - 1] = true;
		}
	}

	return true;
}

bool CheckCols() {
	for (int j = 0; j < ROW_SIZE; j++) {
		bool check[COL_SIZE] = { false, };

		for (int i = 0; i < COL_SIZE; i++) {
			if (check[map[i][j] - 1]) return false;
			check[map[i][j] - 1] = true;
		}
	}

	return true;
}

bool CheckBoxes() {
	for (int row = 0; row < ROW_SIZE; row += 3) {
		for (int col = 0; col < COL_SIZE; col += 3) {
			bool check[COL_SIZE] = { false, };

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (check[map[row + i][col + j] - 1]) {
						return false;
					}
					check[map[row + i][col + j]- 1] = true;
				}
			}
		}
	}

	return true;
}

void PrintMap() {
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++) {
			printf("%d ", map[i][j]);
		}
		putchar('\n');
	}
}

bool solution(int idx) {
	if (idx == blank_pos.size()) {
		//숫자를 대입했을 때 문제가 없는지 판단

		//putchar('\n');
		//PrintMap();
		//putchar('\n');


		if (!CheckBoxes()) return false;
		if (!CheckCols()) return false;
		if (!CheckRows()) return false;

		return true;
	}

	for (int i = 1; i <= 9; i++) {
		//0~9까지 가능한 값을 모두 시도함
		if (!CheckBox(idx, i)) continue;
		if (!CheckCol(idx, i)) continue;
		if (!CheckRow(idx, i)) continue;

		int x = blank_pos[idx].second;
		int y = blank_pos[idx].first;

		map[y][x] = i;

		//putchar('\n');
		//PrintMap();
		//putchar('\n');

		if (solution(idx + 1)) {
			return true;
		}
		map[y][x] = 0;
	}

	return false;
}

int main() {
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++) {
			scanf("%d", &map[i][j]);

			if (!map[i][j]) blank_pos.push_back(make_pair(i, j));
		}
	}

	//첫 번째 빈칸부터 탐색을 시작
	if (solution(0)) {
		PrintMap();
	}

	return 0;
}