#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int biggest_block;

void Save(int origin[21][21], int board[21][21]) {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			origin[i][j] = board[i][j];
		}
	}
}

void Move(int board[21][21], int dir) {
	if (dir == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				bool is_moved = false;
				int cur_y = i, cur_x = j;

				while (board[cur_y][cur_x - 1] == 0) {
					is_moved = true;
					cur_x--;
				}

				if (is_moved) {
					board[cur_y][cur_x] = board[i][j];
					board[i][j] = 0;
				}
			}
		}
	} else if (dir == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 2; j >= 0; j--) {
				bool is_moved = false;
				int cur_y = i, cur_x = j;

				while (board[cur_y][cur_x + 1] == 0) {
					is_moved = true;
					cur_x++;
				}

				if (is_moved) {
					board[cur_y][cur_x] = board[i][j];
					board[i][j] = 0;
				}
			}
		}
	} else if (dir == 0) {
		for (int j = 0; j < N; j++) {
			for (int i = 1; i < N; i++) {
				bool is_moved = false;
				int cur_y = i, cur_x = j;

				while (board[cur_y - 1][cur_x] == 0) {
					is_moved = true;
					cur_y--;
				}

				if (is_moved) {
					board[cur_y][cur_x] = board[i][j];
					board[i][j] = 0;
				}
			}
		}
	} else if (dir == 2) {
		for (int j = 0; j < N; j++) {
			for (int i = N - 2; i >= 0; i--) {
				bool is_moved = false;
				int cur_y = i, cur_x = j;

				while (board[cur_y + 1][cur_x] == 0) {
					is_moved = true;
					cur_y++;
				}

				if (is_moved) {
					board[cur_y][cur_x] = board[i][j];
					board[i][j] = 0;
				}
			}
		}
	}
}

void Merge(int board[21][21], int dir) {
	if (dir == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {
				if (board[i][j] == board[i][j + 1]) {
					board[i][j] = board[i][j] + board[i][j + 1];
					board[i][j + 1] = 0;
				}
			}
		}
	} else if (dir == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j > 0; j--) {
				if (board[i][j] == board[i][j - 1]) {
					board[i][j] = board[i][j] + board[i][j - 1];
					board[i][j - 1] = 0;
				}
			}
		}
	} else if (dir == 0) {
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N - 1; i++) {
				if (board[i][j] == board[i + 1][j]) {
					board[i][j] = board[i][j] + board[i + 1][j];
					board[i + 1][j] = 0;
				}
			}
		}
	} else if (dir == 2) {
		for (int j = 0; j < N; j++) {
			for (int i = N - 2; i > 0; i--) {
				if (board[i][j] == board[i - 1][j]) {
					board[i][j] = board[i][j] + board[i - 1][j];
					board[i - 1][j] = 0;
				}
			}
		}
	}
}

void dfs(int cnt_move, int board[21][21]) {

	if (cnt_move > 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				biggest_block = max(biggest_block, board[i][j]);
			}
		}
		return;
	}

	int origin[21][21];
	Save(origin, board);

	for (int i = 0; i < 4; i++) {
			Move(board, i);
			Merge(board, i);
			Move(board, i);
			dfs(cnt_move + 1, board);
			Save(board, origin);
	}
}

int main() {
	biggest_block = 0;
	int board[21][21];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	
	if (N == 1) {
		printf("%d", board[0][0]);
	} else {
		dfs(0, board);
		printf("%d", biggest_block);
	}
}