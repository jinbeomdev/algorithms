#include <iostream>
#include <string>

using namespace std;

int numbers[9];

void IncreaseNumbers() {
	for (int i = 0; i < 9; i++) {
		if (i == 6) numbers[i]++;
		numbers[i]++;
	}
}
int main() {
	string s;
	cin >> s;

	int answer = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '9') s[i] = '6';

		if (numbers[s[i] - '0'] < 1) {
			answer++;
			IncreaseNumbers();
		}

		numbers[s[i] - '0']--;
	}

	cout << answer;
}