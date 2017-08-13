#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> schools;

int f(int picked, int school) {
	if (school == N - 1) {
		return 1;
	}

	for (int i = schools[school][0]; i < schools[school][1]; i++) {
		if (i > picked) {
			f(i, school++);
		}
		else {
			f(picked, school++);
		}
	}
}

int main() {

	cin >> N;

	schools = vector<vector<int>>(N, vector<int>(2, 0));

	//1 ≤ ai ≤ bi ≤ 109

	for (int i = 0; i < N; i++) {
		cin >> schools[i][0] >> schools[i][1];
	}

	//i번 학교는 축제에 보트를 하나도 내보내지 않을 수 있다.
	//i번 학교가 보트를 내보내기로 한 경우에는 i보다 번호가 작은 그 어떠한 학교가 내보낸 보트 수 보다 많은 수의 보트를 내보내야 함.
	//최소한 한 학교는 내보낸 경우만 계산에 포함.

	f(0, 0);
}