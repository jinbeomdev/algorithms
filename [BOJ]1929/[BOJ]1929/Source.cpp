#include <stdio.h>
#include <string.h>

const int MAX = 1000001;
bool isPrime[MAX];

int main() {
	memset(isPrime, true, sizeof(isPrime));
	int begin, finish;

	scanf("%d%d", &begin, &finish);

	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i < MAX; i++) {
		if (!isPrime[i]) continue;

		for (int j = i + i; j < MAX; j += i) {
			isPrime[j] = false;
		}
	}

	for (int i = begin; i <= finish; i++) {
		if (isPrime[i]) {
			printf("%d\n", i);
		}
	}
}