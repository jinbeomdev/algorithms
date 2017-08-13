#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;
	getline(cin, s);

	vector<int> alpha = vector<int>('Z' - 'A' + 1, 0);

	for (int i = 0; i < s.size(); i++) {
		alpha[s[i] - 'A'] += 1;
	}

	for (int i = 0; i < alpha.size(); i++) {
		int odd = 0;
		if (alpha[i] % 2 == 1) {
			odd += 1;
		}
		if (odd > 1) {
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}


}