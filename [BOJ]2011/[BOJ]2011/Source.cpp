#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAX = 5010;
const int MOD = 1000000;
int dp[MAX] = {};

int main() {
	string cipher;

	cin >> cipher;

	if (cipher.size() == 1 && cipher[0] == '0') {
		printf("0");
		return 0;
	}

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= cipher.size(); i++) {
		if ((cipher[i - 1] - '0') > 0) {
			dp[i] = (dp[i] + dp[i - 1]) % MOD;
		}

		int x = (cipher[i - 2] - '0') * 10 + (cipher[i - 1] - '0');

		if (x >= 10 && x <= 26) {
			dp[i] = (dp [i]  + dp[i - 2]) % MOD;
		}
	}

	printf("%d", dp[cipher.size()]);
	return 0;
}