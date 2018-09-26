#include <stdio.h>
#include <string.h>

#include <algorithm>

using namespace std;

const int MAX = 1000;

int main() {
	int N, L;
	int water[MAX];

	scanf("%d%d", &N, &L);

	for (int i = 0; i < N; i++) {
		scanf("%d", &water[i]);
	}

	sort(water, water + N);

	int answer = 0;
	int here = water[0];
	for (int i = 0; i < N; i++) {
		if (here + L - 1 < water[i]) {
			here = water[i];
			answer++;
		}
	}

	printf("%d", answer + 1);
}