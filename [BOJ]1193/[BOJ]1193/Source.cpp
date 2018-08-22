#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	int sum = 1;
	int i = 1;
	while (sum < N) {
		i = i + 1;
		sum = sum + i;
	}

	sum = sum - i;

	if (i % 2 == 0) {
		printf("%d/%d", 1 + N - sum - 1, i - (N - sum) + 1);
	} else {
		printf("%d/%d", i - (N - sum) + 1, 1 + N - sum - 1);
	}
}