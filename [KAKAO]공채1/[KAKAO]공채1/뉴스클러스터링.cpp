#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

string getElement(const string &s, int i) {
	char a = tolower(s[i]);
	char b = tolower(s[i + 1]);
	return string(1, a) + string(1, b);
}

bool IsAlpha(const string &s, int i) {
	if (!isalpha(s[i]) || !isalpha(s[i + 1])) return false;
	return true;
}

int solution2(string str1, string str2) {

}

int solution(string str1, string str2) {
	multiset<string> str1_set;
	multiset<string> str2_set;

	int i = 0;
	int j = 0;
	while (i < str1.size() - 1 || j < str2.size() - 1) {
		if (IsAlpha(str1, i)) {
			str1_set.insert(getElement(str1, i));
		}

		if (IsAlpha(str2, j)) {
			str2_set.insert(getElement(str2, j));
		}
		i++;
		j++;
	}

	while (i < str1.size() - 1) {
		if (IsAlpha(str1, i)) {
			str1_set.insert(getElement(str1, i));
		}
		i++;
	}

	while (j < str2.size() - 1) {
		if (IsAlpha(str2, j)) {
			str1_set.insert(getElement(str2, j));
		}
		j++;
	}

	if (str1_set.size() == 0 && str2_set.size() == 0) {
		return 65536;
	}

	vector<string> v(str1_set.size());
	vector<string>::iterator it;

	it = set_intersection(str1_set.begin(), str1_set.end(), str2_set.begin(), str2_set.end(), v.begin());
	v.resize(it - v.begin());
	
	int num_intersection = v.size();
	int num_union = str1_set.size() + str2_set.size() - num_intersection;

	double ret = (double)num_intersection / (double)num_union * 65536;
	return (int)ret;
}

int main() {
	printf("%d", solution("aaa", "aaaa"));
}