#include <cstdio>
#include <string>

using namespace std;

bool isSix(int n) {
	string s = to_string(n);
	for (int i = 0; i <= s.size() - 3; i++) {
		if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6') return true;
	}
	return false;
}

int main() {
	int N;
	scanf("%d", &N);

	int i = 666;
	while (N > 0) {
		if (isSix(i)) N--;
		i++;
	}

	printf("%d", i - 1);
}