#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() {
	int N;
	const int RANGE = 10001;
	short int psum[RANGE] = {};

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);

		psum[input]++;
	}

	for (int i = 0; i < RANGE; i++) {
		for (int j = 0; j < psum[i]; j++) {
			printf("%d\n", i);
		}
	}
}