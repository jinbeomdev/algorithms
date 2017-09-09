//1315¹ø: RPG
#include <iostream>
#include <vector>

using namespace std;

const int max(int a, int b) { return (a < b) ? b : a; }


int N;
vector<bool> cleared;
vector<pair<int, pair<int, int>>> quests;
int dp[1001][1001];

int f(int STR, int INT, int stat) {
	if (dp[STR][INT] != -1) return dp[STR][INT];

	dp[STR][INT] = 0;

	for (int i = 0; i < N; i++) {
		if ((STR >= quests[i].second.first ||
			INT >= quests[i].second.second) &&
			cleared[i] == false)
		{
			answer++;
			cleared[i] = true;
			stat += quests[i].first;
		}
	}

	if (stat > 0) {
		dp[STR][INT] = max(f(STR + 1, INT, stat - 1, answer),
			f(STR, INT + 1, stat - 1, answer));
	}

	return dp[STR][INT];
}

int main() {

	cin >> N;

	cleared = vector<bool>(N, false);
	quests = vector<pair<int, pair<int, int>>>(N);
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		int STR, INT, PNT;
		cin >> STR >> INT >> PNT;

		quests[i] = make_pair(PNT, make_pair(STR, INT));
	}

	f(1, 1, 0, 0);

	cout << dp[1][1];
}