#include <cstdio>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	size_t arr1_size = arr1.size();
	size_t arr2_size = arr2.size();

	if (arr1_size != arr2_size) {
		assert(true);
	}

	vector<int> arr3;
	for (size_t i = 0; i < arr1_size; i++) {
		arr3.push_back(arr1[i] | arr2[i]);
	}

	vector<string> ret;
	for (int map_content : arr3) {
		int mask = 1 << n - 1;
		string s = "";

		for (int i = 0; i < n; i++) {
			if ((map_content & mask) > 0) {
				s += '#';
			} else {
				if(s.back() != ' ') s += ' ';
			}

			mask = mask >> 1;
		}

		ret.push_back(s);
	}

	return ret;
}

int main() {
	int n = 6;
	vector<int> arr1;
	vector<int> arr2;

	arr1.push_back(46);
	arr1.push_back(33);
	arr1.push_back(33);
	arr1.push_back(22);
	arr1.push_back(31);
	arr1.push_back(50);

	arr2.push_back(27);
	arr2.push_back(56);
	arr2.push_back(19);
	arr2.push_back(14);
	arr2.push_back(14);
	arr2.push_back(10);

	vector<string> ret = solution(n, arr1, arr2);

	for (auto a : ret) {
		printf("%s\n", a.c_str());
	}
}