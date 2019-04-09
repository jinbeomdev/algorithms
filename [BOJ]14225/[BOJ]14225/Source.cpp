#include <stdio.h>

using namespace std;

int N;
int S[20];
bool comb[20 * 100000 + 10];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		S[i] = a;
	}

	for (int i = 0; i < (1 << N); i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				sum += S[j];
			}
		}
		comb[sum] = true;
	}

	for (int i = 1;; i++) {
		if (comb[i] == false) {
			printf("%d", i);
			break;
		}
	}

	return 0;
}