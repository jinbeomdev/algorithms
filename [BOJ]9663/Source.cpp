#include <cstdio>

int N;
int answer;

int cols[14] = { false, };
int d1[27] = { false, }; // 오른쪽으로 기울어진 대각선
int d2[27] = { false, }; // 왼쪽으로 기울어진 대각선

void dfs(int row) {
	if (row == N) {
		answer++;
		return;
	}

	for (int col = 0; col < N; col++) {
		if (cols[col]) continue;
		if (d1[row + col] || d2[(N - 1) + (row - col)]) continue;

		cols[col] = d1[row + col] = d2[(N - 1) + (row - col)] = true;
		dfs(row + 1);
		cols[col] = d1[row + col] = d2[(N - 1) + (row - col)] = false;
	}	
}

int main() {
	answer = 0;

	scanf("%d", &N);

	dfs(0);

	printf("%d", answer);
}