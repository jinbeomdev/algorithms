//11047: µ¿Àü 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int N, K;
	vector<int> A;
	int answer = 0;

	cin >> N >> K;
	A = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end(), greater<int>());

	//for (int i = 0; i < N; i++) {
	//	cout << A[i] << endl;
	//}

	while (K > 0) {
		for (int i = 0; i < N; i++) {
			if (K - A[i] >= 0) {
				K = K - A[i];
				answer++;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}