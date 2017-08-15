//1065¹ø: ÇÑ¼ö
#include <iostream>

using namespace std;

bool f(int n) {
	int num[4];
	int diff;
	num[0] = n / 1000;
	num[1] = (n % 1000) / 100;
	num[2] = ((n % 1000) % 100) / 10;
	num[3] = (((n % 1000) % 100) % 10);

	if (num[0] == 0 && num[1] == 0) {
		return true;
	}
	else if (num[0] == 0) {
		if (num[1] - num[2] == num[2] - num[3]) return true;
	}
	else {
		if ((num[0] - num[1] == num[1] - num[2]) &&
			(num[1] - num[2] == num[2] == num[3]))
			return true;
	}
	return false;
}

int main() {
	int N;
	int answer = 0;
	
	cin >> N;

	for (int i = N; i > 0; i--) {
		if (f(i)) {
			answer++;
		}
	}
	cout << answer;
}