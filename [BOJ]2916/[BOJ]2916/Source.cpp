#include <stdio.h>

int N, K;
int angle[10];
bool canMake[360];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", angle + i);
	}

	canMake[0] = true;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < 360; k++) {
			for (int j = 0; j < 360; j++) {
				if (!canMake[j]) continue;
				canMake[(j - angle[i] + 360) % 360] = true;
				canMake[(j + angle[i]) % 360] = true;
			}
		}
	}

	for (int i = 0; i < K; i++) {
		int qurey;
		scanf("%d", &qurey);
		puts(canMake[qurey] ? "YES" : "NO");
	}
}