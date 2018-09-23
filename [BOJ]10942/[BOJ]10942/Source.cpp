#include <stdio.h>

const int MAX = 2000;

int arr[MAX];
int dp[MAX][MAX];

int main() {
	int N, M;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
	}

	scanf("%d", &M);

	for(int mid = 0; mid < N; mid++) {
		int left = mid; //È¦¼ö
		int right = mid; //È¦¼ö

		int even_left = mid;
		int even_right = mid + 1;

		while (left >= 0 && right < N) {
			if (arr[left] != arr[right]) {
				dp[left][right] = 0;
				break;
			} else {
				dp[left][right] = 1;
			}
			left--;
			right++;
		}

		while (left >= 0 && right < N) {
			dp[left][right] = 0;
			left--;
			right++;
		}

		while (even_left >= 0 && even_right < N) {
			if (arr[even_left] != arr[even_right]) {
				dp[even_left][even_right] = 0;
				break;
			} else {
				dp[even_left][even_right] = 1;
			}
			even_left--;
			even_right++;
		}

		while (even_left >= 0 && even_right < N) {
			dp[even_left][even_right] = 0;
			even_left--;
			even_right++;
		}
	}

	for (int i = 0; i < M; i++) {
		int S, E;

		scanf("%d%d", &S, &E);

		printf("%d\n", dp[S - 1][E - 1]);
	}

	return 0;
}