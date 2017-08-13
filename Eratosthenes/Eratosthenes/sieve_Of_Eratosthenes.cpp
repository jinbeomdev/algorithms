#include <iostream>
using namespace std;
#define MAX 1000000
bool isPrime[MAX + 1];
int prime[MAX + 1], cnt, num, testcase, T;

void sieve_Of_Eratosthenes(int N) {
	for (int i = 2; i <= N; i++) {
		isPrime[i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		if (isPrime[i] == 0) continue;

		for (int j = i + i; j <= N; j += i) {
			isPrime[j] = 0;
		}
	}
}

int main() {
	sieve_Of_Eratosthenes(MAX);
	cin >> testcase;
	while (testcase != T) {
		T++;
		cin >> num;
		cout << "Case #" << T << endl;
		if (isPrime[num]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}