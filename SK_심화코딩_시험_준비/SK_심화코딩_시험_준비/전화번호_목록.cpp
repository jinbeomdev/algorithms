#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	map<string, bool> m;

	for (string phone_number : phone_book) {

		for (int i = 1; i < phone_number.size(); i++) {
			char dest[21];
			size_t size = phone_number.copy(dest, i, 0);
			dest[size] = '\0';
			m[string(dest)] = true;
		}
	}

	for (string phone_number : phone_book) {
		if (m.find(phone_number) != m.end()) return false;
	}

	return true;
}

int main() {
	vector<string> s;
	s.push_back("113");
	s.push_back("12340");
	s.push_back("123440");
	s.push_back("12345");
	s.push_back("98346");
	solution(s);
}