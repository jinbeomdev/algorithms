#include <iostream>
using namespace std;

int main() {
	int T, test_case;
	int N, K;

	cin >> T;
	for (test_case = 0; test_case < T; test_case) {
		bool *a; //N���� ������� ���� �Ǵ�
		int cnt;; //N���� ������� �������.
		int walker = 1;//���� ����� ������ ������
		cin >> N >> K;

		cnt = N;
		a = new bool[N];
		for (int i = 0; i < N; i++) {
			a[i] = 0; //0�� ����ִ�. 1�� �׾���
		}

		while (cnt >= 2) {
			if (a[walker] == 1) continue;
			else {
				a[walker] = 1;
				cnt--;
				walker = (walker + K) % N;
			}
		}

		for (int i = 0; i < N; i++) {
			if (a[i] == 0) {
				if (i == 0) cout << N << " ";
				else cout << i << " "; 
			}
		}
	}
}