#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

//�ܰ� ��ȣ �м� ������ �ذ��ϴ� �������� �˰���
//int offlien(const vector<int>& signals, int K) {
//	vector<long long> psum(signals.size());
//	// signals�� �κ� ������ �ٲ���.
//	psum[0] = signals[0];
//	for (int i = 1; i < signals.size(); ++i) {
//		psum[i] = signals[i] + psum[i - 1];
//	}
//	int ret = 0, tail = 0;
//	for (int head = 0; head < psum.size(); ++head) {
//		// psum[head] + k <= psum[tail]�� ������ �� ���� tail�� �ڷ� �ű��.
//		while (tail + 1 < psum.size() && psum[head] + K > psum[tail])
//			++tail;
//		//���� psum[head] + K == psum[tail] �̶�� ���� �Ǵ� ������ �ϳ� ã�Ҵ�!
//		if (psum[head] + K == psum[tail])
//			ret++;
//	}
//	return ret;
//}

//�ܰ� ��ȣ �м� ������ �ذ��ϴ� �¶��� �˰���

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
//	RNG rng; // ��ȣ ���� �����ϴ� ���� ������
//	int ret = 0;
//	long long psum = 0;
//	queue<long long> psums;
//	for (int i = 0; i < N; ++i) {
//		//tail�� �� ĭ �ڷ� �ű��.
//		psum += rng.next();
//		psums.push(psum);
//		//psu[head] + K >= psum[tail]�� ������ ������ head�� �ű��.
//		while (psums.front() + k < psum)
//			psums.pop();
//		//���� �ϳ� ã�� ���
//		if (psums.front() + k == psum)
//			++ret;
//	}
//}


//���� § �ҽ�
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