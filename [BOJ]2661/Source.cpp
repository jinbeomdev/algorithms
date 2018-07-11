#include <cstdio>
#include <cstdlib>

int length;
int permutation[80];

bool find(int idx) {
	if (idx == length) {
		//좋은 수열인지 판단
		bool is_good = true;
		for (int i = 0; i < length; i++) {
			if (i == 0 && abs(permutation[0] - permutation[1]) != 1) {
				is_good = false;
			} else if (i == length - 1 && abs(permutation[length - 1] - permutation[length - 2]) == 1) {
				is_good = false;
			} else if (abs(permutation[i] - permutation[i - 1]) != 1 || abs(permutation[i] - permutation[i + 1]) != 1) {
				is_good = false;
			}
		}

		if (is_good) {
			for (int i = 0; i < length; i++) {
				printf("%d", permutation[i]);
			}
			return true;
		}
		else {
			return false;
		}
	}
	
	for (int i = 1; i <= 3; i++) {
		permutation[idx] = i;
		if(find(idx + 1)) return true;
	}

	return false;
}

int main() {
	scanf("%d", &length);

	find(0);

	return 0;
}