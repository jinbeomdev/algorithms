#include <cstdio>

int N, M;
int budget[10000];
int answer = 0;
int sum = 0;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &budget[i]);

		if (answer < budget[i]) answer = budget[i];

		sum += budget[i];
	}

	scanf("%d", &M);

	if (sum < M) {
		printf("%d", answer);
		return 0;
	}

	int left = 1;
	int right = answer;
	while (left <= right) {
		sum = 0;
		int mid = (left + right) / 2;

		for (int i = 0; i < N; i++) {
			if (mid < budget[i]) {
				sum += mid;
			} else {
				sum += budget[i];
			}
		}

		if (sum <= M) {
			answer = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	printf("%d", answer);

	return 0;
}