//12013¹ø: 248°ÔÀÓ
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

#define __max(a,b) (((a) > (b)) ? (a) : (b))



int main() {
	int N;
	vector<int> numbers;
	vector<vector<int>> cache;
	int ret = 0;

	cin >> N;

	numbers = vector<int>(N);
	cache = vector<vector<int>>(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	for (int len = 1; len <= N; len++) {
		for (int i = 0; i + len <= N; i++) {
			int j = i + len - 1;
			cache[i][j] = -1;
			if (len == 1) {
				cache[i][j] = numbers[i];
			}
			for (int k = i; k < j; k++) {
				if (cache[i][k] == cache[k + 1][j] && cache[i][k] > 0) {
					cache[i][j] = __max(cache[i][j], cache[i][k] + 1);
				}
			}
			ret = __max(ret, cache[i][j]);
		}
	}

	cout << ret;
}