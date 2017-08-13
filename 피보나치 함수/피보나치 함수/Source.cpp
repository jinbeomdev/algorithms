#include <iostream>
using namespace std;
int zero;
int one;

int fibonacci(int n) {
	if (n == 0) {
		zero++;
		return 0;
	}
	else if (n == 1) {
		one++;
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	int T, test_case;
	int N;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		zero = 0;
		one = 0;
		
		cin >> N;
		fibonacci(N);

		cout << zero << " " << one << endl;
	}
}