#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define __max(a,b) (((a) > (b)) ? (a) : (b))
int main() {
	int N;
	vector<int> rope;
	int Answer = 0;

	cin >> N;

	rope = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}

	sort(rope.begin(), rope.end());

	for (int i = 0; i < N; i++) {
		Answer = __max(Answer, __max(rope[i], rope[i] * (N - i)));
	}

	cout << Answer;
}