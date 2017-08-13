#include <iostream>
using namespace std;

int main() {
	int T, test_case;
	int N, K;

	cin >> T;
	for (test_case = 0; test_case < T; test_case) {
		bool *a; //N명의 병사들의 죽음 판단
		int cnt;; //N명의 병사들이 살아있음.
		int walker = 1;//죽을 병사들 선택할 포인터
		cin >> N >> K;

		cnt = N;
		a = new bool[N];
		for (int i = 0; i < N; i++) {
			a[i] = 0; //0은 살아있다. 1은 죽었다
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