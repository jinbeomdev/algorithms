#include <iostream>
using namespace std;

int main() {
	int T, test_case;

	cin >> T;
	
	for (test_case = 0; test_case < T; test_case++) {
		int friday = 5;
		int N;
		int *arr;
		int num;
		int hp;
		int cnt = 0;

		cin >> N; //N¿œ
		arr = new int[N];

		for (int i = 0; i < N; i++) {
			arr[i] = 0;
		}
		
		cin >> num;

		for (int i = 0; i < num; i++) {
			cin >> hp;

			for (int j = hp; j <= N; j += hp) {
				if ((j - 1) % friday == 0) continue;
				else {
					arr[j - 1] = 1;
				}
				
				if (j >= friday)
					friday += 7;
			}	
		}

		for (int i = 0; i < N; i++) {
			if (arr[i] == 1)
				cnt++;
		}

		cout << cnt << endl;

		delete[] arr;
	}
	
	return 0;
}