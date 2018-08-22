#include <cstdio>

int N;

int getLimit(int n) {
	return 1 + 6 * n * (n - 1) / 2;
}

int main() {
	scanf("%d", &N);

	int shortest_path = 1;
	while (getLimit(shortest_path) < N) {
		shortest_path++;
	}

	printf("%d", shortest_path);
}