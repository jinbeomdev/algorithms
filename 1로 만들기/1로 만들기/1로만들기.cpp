#include <iostream>
#include <vector>
using namespace std;

inline int min(int a, int b) { return (((a) < (b)) ? (a) : (b)); }

int main() {
	int X;
	int DPSize;
	vector<int> DP;

	cin >> X;

	DP = vector<int>(X + 1, 0);
	DPSize = DP.size();

	for (int i = 0; i < DPSize; i++) {
		if (i == 0 || i == 1) {
			DP[i] = 0;
		}
		else {
			DP[i] = DP[i - 1] + 1;
			if (i % 2 == 0)
				DP[i] = min(DP[i / 2] + 1, DP[i]);
			if (i % 3 == 0)
				DP[i] = min(DP[i / 3] + 1, DP[i]);
		}
	}

	cout << DP[X];
}