#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))

int main() {
	string a, b;
	vector<vector<int>> dp;

	getline(cin, a);
	getline(cin, b);

	dp = vector<vector<int>>(a.size() + 1, vector<int>(b.size() + 1, 0));

	for (int i = 0; i < dp.size(); i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j < dp[0].size(); j++) {
		dp[0][j] = 0;
	}

	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp[i].size(); j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[a.size()][b.size()] << endl;
}