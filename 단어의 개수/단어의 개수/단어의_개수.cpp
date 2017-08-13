#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	int Answer = 1;

	getline(cin, s);

	for (auto it = s.begin(); it < s.end(); it++) {
		if (*it == ' ') Answer++;
	}

	cout << Answer;
}