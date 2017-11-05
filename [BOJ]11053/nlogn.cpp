#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
	int N;
	vector<int> LIS;
	
	cin >> N;

	LIS.push_back(-INF);
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;

		if (LIS.back() < val) {
			LIS.push_back(val);
		}
		else {
			auto it = lower_bound(LIS.begin(), LIS.end(), val);
			*it = val;
		}
	}

	cout << LIS.size() - 1;
}