#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

int dp[101][101][101];

int main() {
	string a, b, c;
	getline(cin, a);
	getline(cin, b);
	getline(cin, c);
	a = " " + a;
	b = " " + b;
	c = " " + c;

	for (int i = 1; i < a.length(); i++) {
		for (int j = 1; j < b.length(); j++) {
			for (int k = 1; k < c.length(); k++) {
				if (a[i] == b[j] && b[j] == c[k] && a[i] == c[k]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1] });
				}
			}
		}
	}

	cout << dp[a.length() - 1][b.length() - 1][c.length() - 1];
}