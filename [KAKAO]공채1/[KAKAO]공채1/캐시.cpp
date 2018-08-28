#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(string& a, string& b) {
	if (a.size() != b.size()) return false;

	for (int i = 0; i < a.size(); i++) {
		if (tolower(a[i]) != tolower(b[i])) return false;
	}

	return true;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> cache;

	for (int i = 0; i < cities.size(); i++) {
		bool is_hit = false;
		for (int j = 0; j < cache.size(); j++) {
			//hit
			if (Comp(cities[i], cache[j])) {
				is_hit = true;
				answer += 1;
				string hold = cache[j];
				cache.erase(cache.begin() + j);
				cache.push_back(hold);
				break;
			}
		}

		if (!is_hit) {
			if (cache.size() < cacheSize) {
				cache.push_back(cities[i]);
			} else if (cache.size() > 0) {
				cache.erase(cache.begin());
				cache.push_back(cities[i]);
			}
			answer += 5;
		}
	}

	return answer;
}

int main() {
	vector<string> cities;
	cities.push_back("Jeju");
	cities.push_back("Pangyo");
	cities.push_back("Seoul");
	cities.push_back("Jeju");
	cities.push_back("Pangyo");
	cities.push_back("Seoul");
	cities.push_back("Jeju");
	cities.push_back("Pangyo");
	cities.push_back("Seoul");
	printf("%d", solution(3, cities));
}