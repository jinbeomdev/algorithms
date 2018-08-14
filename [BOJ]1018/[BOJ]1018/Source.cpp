#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int ret = 1e9;
char board[51][51];
char white_board[8][8];
char black_board[8][8];

void init() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				white_board[i][j] = (j % 2 == 0) ? 'W' : 'B';
				black_board[i][j] = (j % 2 == 0) ? 'B' : 'W';
			} else {
				white_board[i][j] = (j % 2 == 0) ? 'B' : 'W';
				black_board[i][j] = (j % 2 == 0) ? 'W' : 'B';
			}
		}
	}
}

void Check(int y, int x) {
	int white = 0;
	int black = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (board[i][j] != white_board[i - y][j - x]) white++;
			if (board[i][j] != black_board[i - y][j - x]) black++;
		}
	}

	ret = min(ret, min(black, white));
}

int main() {
	init();

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
			scanf("%s", board[i]);
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			Check(i, j);
		}
	}

	printf("%d", ret);
}