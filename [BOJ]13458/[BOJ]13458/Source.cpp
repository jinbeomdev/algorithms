#include <cstdio>

long long num[1000001];
int main() {
	long long N, B, C;
	long long ret;
	scanf("%lld%", &N);
	ret = N;
	for (long long i = 0; i < N; i++) {
		scanf("%lld", &num[i]);
	}
	scanf("%lld%lld", &B, &C);
	for (long long i = 0; i < N; i++) {
		num[i] = num[i] - B;
		if (num[i] < 0) num[i] = 0;
	}
	for (long long i = 0; i < N; i++) {
		if (num[i] == 0) continue;
		long long q = num[i] / C;
		long long p = num[i] % C;
		if (q == 0) {
			ret++;
		} else if (p == 0) {
			ret += q;
		} else {
			ret += (q + 1);
		}
	}
	printf("%lld", ret);
}