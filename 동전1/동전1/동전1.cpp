#include <iostream>
#include <vector>
using namespace std;

int main() {
	//N : ������ ���� K : �������� ��ġ ��
	int N, K, Answer = 0;
	vector<int> coins;
	vector<int> DP;
	
	cin >> N >> K;

	coins = vector<int>(N, 0);
	DP = vector<int>(K + 1, 1);
	
	for (int i = 0; i < coins.size(); i++) {
		cin >> coins[i];
	}

	for (int i = 1; i < DP.size(); i++) {
		for (int j = 1; j < coins.size(); j++) {
			if (i - coins[j] >= 0) {
				DP[i] += DP[i - coins[j]];
			}
		}
	}

	cout << DP[K];
}