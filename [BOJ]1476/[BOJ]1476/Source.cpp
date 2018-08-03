#include <cstdio>

int main() {
	int E, S, B;
	int answer = 1;
	int years[3] = { 1, 1, 1 };
	int limits[3] = { 16, 29, 20 };
	scanf("%d%d%d", &E, &S, &B);
	while (true) {
		if (years[0] == E &&
			years[1] == S &&
			years[2] == B) break;

		answer++;

		for (int i = 0; i < 3; i++) {
			years[i]++;
		}

		for (int i = 0; i < 3; i++) {
			if (years[i] == limits[i]) years[i] = 1;
		}
	}
	printf("%d", answer);
}