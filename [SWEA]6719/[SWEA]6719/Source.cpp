#include <stdio.h>
#include <algorithm>

using namespace std;

int T;
int N, K;
int M[200];

int main() {
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d", &N, &K);

		for (int i = 0; i < N; i++) {
			int val;
			
			scanf("%d", &val);
			
			M[i] = val;
		}

		sort(M, M + N);

		double ret = 0;
		for (int i = N - K; i < N; i++) {
			ret = (double)(ret + M[i]) / 2.0;
		}

		printf("#%d %lf\n", test_case, ret);
	}

	return 0;
}