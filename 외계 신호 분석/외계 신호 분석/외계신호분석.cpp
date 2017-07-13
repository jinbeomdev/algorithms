#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

//외계 신호 분석 문제를 해결하는 오프라인 알고리즘
//int offlien(const vector<int>& signals, int K) {
//	vector<long long> psum(signals.size());
//	// signals를 부분 합으로 바꾸자.
//	psum[0] = signals[0];
//	for (int i = 1; i < signals.size(); ++i) {
//		psum[i] = signals[i] + psum[i - 1];
//	}
//	int ret = 0, tail = 0;
//	for (int head = 0; head < psum.size(); ++head) {
//		// psum[head] + k <= psum[tail]이 만족할 때 까지 tail을 뒤로 옮긴다.
//		while (tail + 1 < psum.size() && psum[head] + K > psum[tail])
//			++tail;
//		//만약 psum[head] + K == psum[tail] 이라면 답이 되는 구간을 하나 찾았다!
//		if (psum[head] + K == psum[tail])
//			ret++;
//	}
//	return ret;
//}

//외계 신호 분석 문제를 해결하는 온라인 알고리즘

//struct RNG {
//	unsigned seed;
//	RNG() : seed(1983) {}
//	unsigned next() {
//		unsigned ret = seed;
//		seed = ((seed * 214013u) + 2531011u);
//		return ret % 10000 + 1;
//	}
//};

//int countPartialSums(int K, int N) {
//	RNG rng; // 신호 값을 생성하는 난수 생성기
//	int ret = 0;
//	long long psum = 0;
//	queue<long long> psums;
//	for (int i = 0; i < N; ++i) {
//		//tail을 한 칸 뒤로 옮긴다.
//		psum += rng.next();
//		psums.push(psum);
//		//psu[head] + K >= psum[tail]을 만족할 때까지 head를 옮긴다.
//		while (psums.front() + k < psum)
//			psums.pop();
//		//답을 하나 찾은 경우
//		if (psums.front() + k == psum)
//			++ret;
//	}
//}


//내가 짠 소스
int signal_analysis(int A[], const int N, const int K) {
	int p = 0, q = 0;
	int sum = 0;
	int Answer = 0;

	while (p < N && q < N) {
		if (sum < K && q < N) {
			sum += A[q++];
		}
		else if (sum > K && p < N) {
			sum -= A[p++];
		}
		else {
			sum += A[q++];
			Answer++;
		}
	}

	return Answer;
}

int main() {
	int T, test_case;
	int N;
	int K;
	int Answer = 0;
	int *sequence;
	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		cin >> K >> N;

		sequence = new int[N];
		sequence[0] = 1983;
		for (int i = 1; i < N; i++) {
			sequence[i] = (sequence[i - 1] * 214013 + 2531011) % (int)pow(2, 32);
		}

		Answer = signal_analysis(sequence, N, K);
		
		cout << Answer << endl;
	}
}