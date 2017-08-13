#include <iostream>
#include <vector>
#include <queue>

#define type long long
using namespace std;

int main() {
	int N;
	type T;
	type sum = 9223372036854775807;
	vector<type> seq;

	cin >> N >> T;

	seq = vector<type>(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}

	//while (T > 0) {
	//	type tempSum = 0;
	//	priority_queue<pair<type, pair<int, int>>> pq;

	//	for (int i = 1; i < N; i++) {
	//		type diff = abs(seq[i - 1] - seq[i]);
	//		tempSum += diff;
	//		pq.push(make_pair(diff, make_pair(i - 1, i)));
	//	}

	//	//수열에서 인접한 수들의 차의 합이 0인 경우 그냥 끝냄
	//	if (tempSum == 0) break;


	//	if (pq.top().second.second + 1 < N &&
	//		seq[pq.top().second.first] < seq[pq.top().second.second] &&
	//		seq[pq.top().second.second] > seq[pq.top().second.second + 1]) {
	//		if (seq[pq.top().second.first] < seq[pq.top().second.second + 1]) {
	//			if ((seq[pq.top().second.second] - seq[pq.top().second.second + 1]) <= T) {
	//				T -= (seq[pq.top().second.second] - seq[pq.top().second.second + 1]);
	//				seq[pq.top().second.second] -= (seq[pq.top().second.second] - seq[pq.top().second.second + 1]);
	//				continue;
	//			}
	//			else {
	//				seq[pq.top().second.second] -= T;
	//				break;
	//			}
	//		}
	//		else {
	//			if ((seq[pq.top().second.second] - seq[pq.top().second.first]) <= T) {
	//				T -= (seq[pq.top().second.second] - seq[pq.top().second.first]);
	//				seq[pq.top().second.second] -= (seq[pq.top().second.second] - seq[pq.top().second.first]);
	//				continue;
	//			}
	//			else {
	//				seq[pq.top().second.second] -= T;
	//				break;
	//			}
	//		}
	//	}
	//	if (seq[pq.top().second.first] < seq[pq.top().second.second]) {
	//		seq[pq.top().second.second]--;
	//	}
	//	else {
	//		seq[pq.top().second.first]--;
	//	}

	//	T--;
	//}

	for (int i = 0; i < N; i++) {
		cout << seq[i] << " ";
	} cout << endl;

	return 0;
}