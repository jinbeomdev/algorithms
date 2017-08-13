#include <iostream>
#include <vector>
using namespace std;

inline int max(int a, int b) {
	return (((a) > (b)) ? (a) : (b));
}


int main() {
	//계단의 개수
	int N;
	vector<int> DP, stairs;

	cin >> N;
	DP = vector<int>(N, 0);
	stairs = vector<int>(N, 0);
	for (int i = 0; i < stairs.size(); i++) {
		cin >> stairs[i];
	}

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			DP[i] = stairs[i];
			continue;
		}
		else if (i == 1) {
			DP[i] = DP[i - 1] + stairs[i];
			continue;
		}
		else if (i == 2) {
			DP[i] = max(DP[i - 2] + stairs[i], stairs[i - 1] + stairs[i]);
			continue;
		}
		else 
			DP[i] = max(DP[i - 2] + stairs[i], DP[i - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << DP[N - 1];
}