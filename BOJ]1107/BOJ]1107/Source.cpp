#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool buttons[10];

int GetLength(int N) {
	int ret = 0;

	if (N == 0) return 1;

	while (N > 0) {
		N = N / 10;
		ret++;
	}

	return ret;
}

bool CanGo(int N) {
	if (N == 0) {
		if (buttons[0]) return true;
		else return false;
	}

	while (N > 0) {
		if (!buttons[N % 10]) return false;
		N = N / 10;
	}
	return true;
}

int main() {
	int N, M;

	memset(buttons, true, sizeof(buttons));

	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; i++) {
		int button;
		scanf("%d", &button);
		buttons[button] = false;
	}

	int backward;
	int forward;
	for (backward = N; backward >= 0; backward--) {
		if (CanGo(backward)) break;
	}

	for (forward = N; forward <= 1000001; forward++) {
		if (CanGo(forward)) break;
	}

	int answer = abs(N - 100);

	if (forward != 1000001) {
		answer = min(answer, abs(N - forward) + GetLength(forward));
	}

	if (backward != -1) {
		answer = min(answer, abs(N - backward) + GetLength(backward));
	}

	printf("%d", answer);
}