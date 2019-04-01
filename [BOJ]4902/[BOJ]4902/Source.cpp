#include <stdio.h>

int N;
int triangle[400][2 * 400 + 1];
int s[400][2 * 400 + 2];
int answer;

void dfs(int row, int left, int right, int sum, int type) {
	if (row < 0 || row >= N ||
		left < 0 || right >= row * 2 + 1) return;

	sum += s[row][right + 1] - s[row][left];

	if (answer < sum) answer = sum;


	if (type == 0) dfs(row + 1, left, right + 2, sum, 0);
	if (type == 1) dfs(row - 1, left - 2, right, sum, 1);
}


int main() {
	int tc = 1;
	while (true) {
		scanf("%d", &N);

		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2 * i + 1; j++) {
				scanf("%d", &triangle[i][j]);
				s[i][j + 1] = s[i][j] + triangle[i][j];
			}
		}

		answer = -100000;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2 * i + 1; j++) {
				if (j % 2) dfs(i, j, j, 0, 1);
				else dfs(i, j, j, 0, 0);
			}
		}

		printf("%d. %d\n", tc, answer);
		tc++;
	}
}