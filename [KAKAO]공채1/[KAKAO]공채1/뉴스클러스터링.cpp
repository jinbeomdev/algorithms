#include <string>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
	int set_str1[676] = {};
	int set_str2[676] = {};

	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	int i = 0;
	int j = 0;
	int index;
	while (i < str1.size() -1 && j < str2.size() - 1) {
		if (isalpha(str1[i]) && isalpha(str1[i + 1])) {
			index = (str1[i] - 'a') * 26 + (str1[i + 1] - 'a');
			set_str1[index]++;
		}

		if (isalpha(str2[j]) && isalpha(str2[j+ 1])) {
			index = (str2[j] - 'a') * 26 + (str2[j + 1] - 'a');
			set_str2[index]++;
		}

		i++;
		j++;
	}

	while (i < str1.size() - 1) {
		if (isalpha(str1[i]) && isalpha(str1[i + 1])) {
			index = (str1[i] - 'a') * 26 + (str1[i + 1] - 'a');
			set_str1[index]++;
		}

		i++;
	}

	while (j < str2.size() - 1) {
		if (isalpha(str2[j]) && isalpha(str2[j + 1])) {
			index = (str2[j] - 'a') * 26 + (str2[j + 1] - 'a');
			set_str2[index]++;
		}

		j++;
	}

	int num_union = 0;
	int num_intersection = 0;

	for (int i = 0; i < 676; i++) {
		num_union += max(set_str1[i], set_str2[i]);
		num_intersection += min(set_str1[i], set_str2[i]);
	}

	if (num_union == 0) {
		return 65536;
	}

	return (int)(((double)num_intersection / (double)num_union) * 65536.0);
}

int main() {
	solution(string("zasdasdasdasdasdz"), string("zzasdasdasda"));
}