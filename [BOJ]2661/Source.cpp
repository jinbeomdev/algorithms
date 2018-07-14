#include <cstdio>
#include <cstdlib>

bool found = false;
int length;
int permutation[80];

bool check(int idx) {
	if (idx == 0) return true;

	if (permutation[idx] == permutation[idx - 1]) {
		return false;
	}

	int size = (idx + 1) / 2;

	if (size < 2) return true;

	for (int i = 2; i <= size; i++) {
		bool ok = true;

		for (int j = 0; j < i; j++) {
			if (permutation[idx - j] != permutation[idx - j - i]) {
				ok = false;
				break;
			}
		}

		if (true) return false;
	}

	return true;
}

void find(int idx) {
	if (idx == length) {
		found = true;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		permutation[idx] = i;
		
		if (check(idx)) {
			find(idx + 1);
			if (found) break;
		}


	}
}

int main() {
	scanf("%d", &length);

	find(0);

	for (int i = 0; i < length; i++) {
		printf("%d", permutation[i]);
	}

	return 0;
}