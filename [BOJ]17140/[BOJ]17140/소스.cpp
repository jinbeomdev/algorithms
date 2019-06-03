#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int A[101][101];
int r, c, k;
int t;
int lengthRow;
int lengthCol;

typedef pair<int, int> pii;

bool comp(pii a, pii b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void operR() {
	int temp[101][101];
	memset(temp, 0, sizeof(temp));

	for (int i = 1; i <= 100; i++) {
		int hashArr[101];
		memset(hashArr, 0, sizeof(hashArr));

		vector<pii> v;

		for (int j = 1; j <= 100; j++) {
			hashArr[A[i][j]]++;
		}

		for (int key = 1; key <= 100; key++) {
			if (hashArr[key]) {
				v.push_back(make_pair(key, hashArr[key]));
			}
		}

		sort(v.begin(), v.end(), comp);

		for (int j = 1, vidx = 0; vidx < v.size(); j += 2, vidx++) {
			temp[i][j] = v[vidx].first;
			temp[i][j + 1] = v[vidx].second;
		}

		if (lengthCol < v.size() * 2) {
			lengthCol = v.size() * 2;
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			A[i][j] = temp[i][j];
		}
	}
}

void operC() {
	int temp[101][101];
	memset(temp, 0, sizeof(temp));

	for (int j = 1; j <= 100; j++) {
		int hashArr[101];
		memset(hashArr, 0, sizeof(hashArr));

		vector<pii> v;

		for (int i = 1; i <= 100; i++) {
			hashArr[A[i][j]]++;
		}

		for (int key = 1; key <= 100; key++) {
			if (hashArr[key]) {
				v.push_back(make_pair(key, hashArr[key]));
			}
		}

		sort(v.begin(), v.end(), comp);

		for (int i = 1, vidx = 0; vidx < v.size(); i += 2, vidx++) {
			temp[i][j] = v[vidx].first;
			temp[i + 1][j] = v[vidx].second;
		}

		if (lengthRow < v.size() * 2) {
			lengthRow = v.size() * 2;
		}
	}

	for (int j = 1; j <= 100; j++) {
		for (int i = 1; i <= 100; i++) {
			A[i][j] = temp[i][j];
		}
	}
}

int main() {
	memset(A, 0, sizeof(A));

	scanf("%d%d%d", &r, &c, &k);

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	t = 0;
	lengthRow = 3;
	lengthCol = 3;

	while (A[r][c] != k && t <= 100) { //A[r][c] == k 이면, A[r][c]가 100을 넘으면 종료
		if (lengthRow < lengthCol) {
			operC();
		}
		else {
			operR();
		}

		/*printf("\n\n%d: \n", t);
		for (int i = 1; i <= lengthRow; i++) {
			for (int j = 1; j <= lengthCol; j++) {
				printf("%d", A[i][j]);
			}
			printf("\n");
		}*/
		t++;
	}

	printf("%d", (t <= 100) ? t : -1);
}