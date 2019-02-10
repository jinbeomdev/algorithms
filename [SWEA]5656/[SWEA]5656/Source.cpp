#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 4;
const int MAX_W = 12;
const int MAX_H = 15;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };
int T, N, W, H;
int board[MAX_H][MAX_W];
int answer;

void leftDown(int copied_board[][MAX_W]) {
	for (int i = 0; i < W; i++) {
		for (int j = H - 2; j >= 0; j--) {
			if (copied_board[j][i] == 0) continue;
			int y = j;
			while (y + 1 < H && copied_board[y + 1][i] == 0) {
				int temp = copied_board[y][i];
				copied_board[y][i] = copied_board[y + 1][i];
				copied_board[y + 1][i] = temp;
				y++;
			}
		}
	}
}

int findHighest(int x, int copied_board[][MAX_W]) {
	int highest = H -1;
	
	for (int i = 0; i < H; i++) {
		if (copied_board[i][x] > 0) {
			highest = i;
			break;
		}
	}

	return highest;
}

void printBoard() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void propagate(int y, int x, int copied_board[][MAX_W]) {
	int length = copied_board[y][x];
	copied_board[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < length; j++) {
			int next_y = y + (dy[i] * j);
			int next_x = x + (dx[i] * j);

			if (next_y < 0 || next_y >= H ||
				next_x < 0 || next_x >= W) continue;

			if (copied_board[next_y][next_x] == 0) continue;

			if (copied_board[next_y][next_x] == 1) {
				copied_board[next_y][next_x] = 0;
				continue;
			}

			propagate(next_y, next_x, copied_board);
		}
	}
}

void dfs(int depth, vector<int> &v) {
	if (depth == N) {
		int copied_board[MAX_H][MAX_W];
		for (int i = 0; i < MAX_H; i++) {
			for (int j = 0; j < MAX_W; j++) {
				copied_board[i][j] = board[i][j];
			}
		}

		for (int i = 0; i < v.size(); i++) {
			propagate(findHighest(v[i], copied_board), v[i], copied_board);
			leftDown(copied_board);
		}

		int totalBrick = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (copied_board[i][j] > 0) {
					totalBrick++;
				}
			}
		}

		if (totalBrick < answer) {
			answer = totalBrick;
		}
		return;
	}

	for (int i = 0; i < W; i++) {
		v.push_back(i);
		dfs(depth + 1, v);
		v.pop_back();
	}
}

int main() {
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		answer = 0;

		scanf("%d%d%d", &N, &W, &H);

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &board[i][j]);
				if (board[i][j] > 0) answer++;
			}
		}

		vector<int> v;
		dfs(0, v);


		printf("#%d %d\n", test_case, answer);
	}
}