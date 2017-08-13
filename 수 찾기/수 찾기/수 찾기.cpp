#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> a;
vector<int> b;

int binary_serach(int findData) {
	int left = 0, right = a.size() - 1;
	int mid;
	
	while (left <= right) {
		mid = (left + right) / 2;

		if (findData < a[mid]) {
			right = mid - 1;
		}
		else if (findData > a[mid]) {
			left = mid + 1;
		}
		else {
			return 1;
		}
	}

	return 0;
}

int main() {
	cin >> N;

	a = vector<int>(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	cin >> M;

	b = vector<int>(M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &b[i]);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < M; i++) {
		if (b[i] < a.front() && b[i] > a.back()) printf("0\n");
		printf("%d\n", binary_serach(b[i]));
	}
}