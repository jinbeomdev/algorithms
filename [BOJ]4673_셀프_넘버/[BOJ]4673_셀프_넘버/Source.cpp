//4673¹ø: ¼¿ÇÁ ³Ñ¹ö
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 10001

int self_number[MAX];

void f(int n) {
	if (n >= MAX) {
		return;
	}

	self_number[n] = 1;
	n = n + n / 10000 + (n % 10000) / 1000 + ((n % 10000) % 1000) / 100 + (((n % 10000) % 1000) % 100) / 10 + ((((n % 10000) % 1000) % 100) % 10);
	f(n);
}

int main() {
	int cnt;
	memset(self_number, 0, sizeof(self_number));

	for (int i = 1; i < MAX; i++) {
		int n;
		if (self_number[i]) continue;
		n = i + i / 10000 + (i % 10000) / 1000 + ((i % 10000) % 1000) / 100 + (((i % 10000) % 1000) % 100) / 10 + ((((i % 10000) % 1000) % 100) % 10);
		f(n);
	}

	for (int i = 1; i < MAX; i++) {
		if (!self_number[i]) {
			cout << i << endl;
		}
	}
}