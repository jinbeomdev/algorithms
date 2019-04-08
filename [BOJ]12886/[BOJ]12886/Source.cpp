#include <stdio.h>

int A, B, C;
int TOTAL;
int visited[1501][1501];

void dfs(int a, int b) {
	if (visited[a][b]) return;
	visited[a][b] = true;
	int rocks[3] = { a, b, TOTAL - a - b };

	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (rocks[i] < rocks[j]) {
				int temp[3] = { a, b, TOTAL - a - b };
				temp[i] += rocks[i];
				temp[j] -= rocks[i];
				dfs(temp[0], temp[1]);
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &A, &B, &C);
	TOTAL = A + B + C;

	if (TOTAL % 3 != 0) {
		printf("0");
		return 0;
	}

	dfs(A, B);

	if (visited[TOTAL / 3][TOTAL / 3]) {
		printf("1");
	}
	else {
		printf("0");
	}

	return 0;
}