#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N, k;

	scanf("%d%d", &N, &k);

	int left = 1;
	int right = k;
	int answer;

	while (left <= right) {
		int mid = (left + right) / 2;
		int num = 0;

		for (int i = 1; i <= N; i++) {
			num += min(mid / i, N);
		}

		if (num >= k) {
			answer = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	printf("%d", answer);
}