//1152번: 단어의 개수
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int cnt = 0;
	getline(cin, s);
	bool space = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') space = true;
		if (s[i] >= 'A' && s[i] <= 'z' && space == true) {
			cnt++;
			space = false;
		}
	}

	cout << cnt;
 }