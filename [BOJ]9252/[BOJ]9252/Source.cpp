#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

string a;
string b;

const int MAX = 1000;
int dp[MAX][MAX];
pair<int, int> back[MAX][MAX];

int lcs(int ai, int bi) {
	if (ai == a.size() || bi == b.size()) return 0;

	int& ret = dp[ai][bi];

	if (ret != -1) return ret;

	if (a[ai] == b[bi]) {
		ret = lcs(ai + 1, bi + 1) + 1;
		back[ai][bi] = make_pair(ai + 1, bi + 1);
		return ret;
	}

	int x = lcs(ai + 1, bi);
	int y = lcs(ai, bi + 1);

	if (x > y) {
		back[ai][bi] = make_pair(ai + 1, bi);
		return ret = x;
	} else {
		back[ai][bi] = make_pair(ai, bi + 1);
		return ret = y;
	}
}

int main() {
	memset(dp, -1, sizeof(dp));

	cin >> a;
	cin >> b;

	printf("%d\n", lcs(0, 0));

	stack<char> s;
	int p = 0;
	int q = 0;
	while (p < a.size() && q < b.size()) {
		if (a[p] == b[q]) printf("%c", a[p]);
		int temp_p = p;
		p = back[p][q].first;
		q = back[temp_p][q].second;
	}
}