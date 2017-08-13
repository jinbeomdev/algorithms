//1110번: 더하기 사이클
#include <iostream>

using namespace std;

int N;
int answer = 0;

void f(int num) {
	if (num == N) {
		return;
	}

	answer++;
	int first = num / 10;
	int second = num % 10;
	int third = (first + second) % 10;
	int newNum = second * 10 + third;
	f(newNum);
}

int main() {
	cin >> N;

	answer++;
	int first = N / 10;
	int second = N % 10;
	int third = (first + second) % 10;
	int newNum = second * 10 + third;
	f(newNum);

	cout << answer;
}