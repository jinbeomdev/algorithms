#include <iostream>
using namespace std;

//�Է�
//ù ��° �ٿ��� �迭 D�� ������ ���� N�� ������ ������ K �� �־�����,
//�� ��° �ٿ��� �迭�� ���� Di�� �־����ϴ�. (Di �� �ڿ���)

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