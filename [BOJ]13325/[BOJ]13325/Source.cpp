#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int cbt[1 << 21]; //complete binary tree (포화이진트리)

int main() {
	int height;
	int total_weight = 0;
	scanf("%d", &height);
	for (int i = 1; i < (1 << height + 1) - 1; i++) {
		int weight;
		scanf("%d", &weight);
		cbt[i] = weight;
		total_weight += weight;
	}

	for (int i = (1 << height + 1) - 2; i > 0; i=i-2) {
		total_weight += abs(cbt[i] - cbt[i - 1]);
		cbt[(i / 2) - 1] += max(cbt[i], cbt[i - 1]);
	}

	printf("%d", total_weight);
}