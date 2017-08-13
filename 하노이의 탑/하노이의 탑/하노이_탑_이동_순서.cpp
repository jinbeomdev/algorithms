#include <iostream>

using namespace std;

int step = 0;

void move(int from, int to) {
	cout << from << " " << to << endl;
}

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		cout << from << " " << to << endl;
	}
	else {
		hanoi(n - 1, from, to, by); step = step + 1;
		move(from, to); step = step + 1;
		hanoi(n - 1, by, from, to); step = step + 1;
	}
}

int main() {
	//장대에 쌓인 원판의 개수 N(1 <= N <= 20)
	int N;

	cin >> N;

	hanoi(N, 1, 2, 3);
	cout << step << endl;
}