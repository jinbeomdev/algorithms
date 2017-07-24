#include <iostream>
#include <string>
using namespace std;
int **matrix;

string quad_tree(int size, int x, int y) {
	int sum = 0;
	for (int i = y; i < size + y; i++) {
		for (int j = x; j < size + x; j++) {
			sum += matrix[i][j];
		}
	}

	if (sum == 0) {
		return "0";
	}
	else if (sum == size * size) {
		return "1";
	}
	else
		return '(' + quad_tree(size / 2, x, y) + quad_tree(size / 2, x + size / 2, y) + quad_tree(size / 2, x, y + size / 2) +
		quad_tree(size / 2, x + size / 2, y + size / 2) + ')';
}

int main() {
	int N;

	cin >> N;
	matrix = new int*[N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int c;
			if ((c = cin.get()) == '\n') {
				matrix[i][j] = cin.get() - 48;
			}
			else {
				matrix[i][j] = c - 48;
			}
		}
	}
	cout << quad_tree(N, 0, 0);
}