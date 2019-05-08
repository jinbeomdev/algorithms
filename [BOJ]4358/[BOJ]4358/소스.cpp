#include <stdio.h>

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int cnt = 0;
	string str;
	map<string, int> m;
	while (getline(cin, str)) {
		cnt++;
		if (m.find(str) == m.end()) {
			m[str] = 1;
		}
		else {
			m[str] += 1;
		}
	}

	map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		printf("%s %.4f\n", it->first.c_str(), ((double)it->second / (double)cnt) * 100);
	}
	return 0;
}