#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, vector<int> tshirts) {
	sort(people.begin(), people.end());
	sort(tshirts.begin(), tshirts.end());

	int answer = 0;
	while (!people.empty() && !tshirts.empty()) {
		if (people.front() <= tshirts.front()) {
			answer++;
			tshirts.erase(tshirts.begin());
			people.erase(people.begin());
		} else {
			tshirts.erase(tshirts.begin());
		}
	}

	return answer;
}