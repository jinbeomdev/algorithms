//11720번: 숫자의 합
#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	char c[100];
	int Answer = 0;
	cin >> N;
	cin >> c;
	for (int i = 0; i < N; i++) {
		Answer += c[i] - '0';
	}
	cout << Answer;
}