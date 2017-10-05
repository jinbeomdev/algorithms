//11399: ATM
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	vector<int> times;
	vector<int> psum;
	int answer = 0;

	cin >> N;

	times = vector<int>(N + 1);
	psum = vector<int>(N + 1);
	
	for (int i = 1; i < N + 1; i++) {
		cin >> times[i];
	}

	sort(times.begin(), times.end());

	for (int i = 1; i < N + 1; i++) {
		psum[i] = psum[i - 1] + times[i];
		answer += psum[i];
	}

	cout << answer;

	return 0;
}