#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool primes[10001] = {0};
int main() {
	int M, N;
	vector<int> seq;
	int min = -1;
	int sum = 0;

	primes[0] = primes[1] = 1;

	cin >> M >> N;

	for (int i = 2; i <= N; i++) {
		if (primes[i]) continue;

		for (int j = i + i; j < 10001; j+=i) {
			primes[j] = 1;
		}
	}

	for (int i = M; i <= N; i++) {
		if (!primes[i]) {
			if (min == -1)
				min = i;
			sum += i;
		}
	}

	if (sum == 0) {
		cout << "-1" << endl;
	}
	else {
		cout << sum << endl <<
			min << endl;
	}
}