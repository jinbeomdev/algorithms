//11062번: 카드 게임
#include <iostream>
#include <vector>

using namespace std;

const int min(int a, int b) { return a < b ? a : b; }

int T, test_case;
int N;
vector<int> cards;
vector<vector<int>> dp;

int f(int left, int right) {
	if (left >= right) return cards[left];

	if (dp[left][right] != -1) return dp[left][right];
	dp[left][right] = 

}

int main() {

	for (test_case = 0; test_case < T; test_case++) {
		cin >> N;

		cards = vector<int>(N);
		dp = vector<vector<int>>(N, vector<int>(N, -1));

		for (int i = 0; i < N; i++)
			cin >> cards[i];

		f(0, N - 1);
	}
}