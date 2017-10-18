//1654 : 랜선 자르기
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const long long int INF = LLONG_MAX;

int main() {
	//첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N
	int N, K;
	vector<long long int> lans;
	long long int left = 0, mid, right = INF;
	long long int answer = 0;

	cin >> N >> K;

	lans = vector<long long int>(N);

	for (int i = 0; i < N; i++) {
		cin >> lans[i];

		//if (right > lans[i]) {
		//	right = lans[i];
		//}
	}

	while (left <= right) {
		long long int cnt = 0;

		mid = (left + right) / 2;

		for (int i = 0; i < N; i++) {
			cnt += (lans[i] / mid);
		}

		if (cnt >= K) {
			left = mid + 1;
			
			if (answer < mid) {
				answer = mid;
			}
		}
		else {
			right = mid - 1;
		}
	}

	cout << answer;
}