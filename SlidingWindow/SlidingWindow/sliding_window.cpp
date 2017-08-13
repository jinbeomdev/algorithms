#include <iostream>
using namespace std;

//입력
//첫 번째 줄에는 배열 D의 원소의 개수 N과 윈도우 사이즈 K 가 주어지고,
//두 번째 줄에는 배열의 원소 Di가 주어집니다. (Di 는 자연수)

int main() {
	int N, K;
	int *D;
	int Answer = 0;
	int sum = 0;

	cin >> N >> K;
	D = new int[N];
	
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}

	for (int i = 0; i < N; i++) {
		if (i < K) {
			sum += D[i];
		}
		else {
			sum = sum - D[i - K] + D[i];
		}
		if (Answer < sum) Answer = sum;
	}

	cout << Answer;
}