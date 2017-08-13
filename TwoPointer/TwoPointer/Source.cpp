#include <iostream>
using namespace std;

int main() {
	int p = 0;
	int q = 0;
	int r = 0;
	int aSize, bSize;
	int *a, *b, *c;

	cin >> aSize;
	a = new int[aSize];
	for (int i = 0; i < aSize; i++) {
		cin >> a[i];
	}
	cin >> bSize;
	b = new int[bSize];
	for (int i = 0; i < bSize; i++) {
		cin >> b[i];
	}
	c = new int[aSize + bSize];

	while (p < aSize) {
		c[r++] = a[p++];
	}

	while (q < bSize) {
		c[r++] = b[q++];
	}

	for (int i = 0; i < aSize + bSize; i++) {
		cout << c[i];
	}
}