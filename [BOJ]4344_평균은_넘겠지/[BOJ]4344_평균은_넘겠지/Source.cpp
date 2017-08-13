//4344번: 평균은 넘겠지
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int N;
		int sum = 0;
		double average;
		int cnt = 0;
		vector<int> scores;

		cin >> N;
		scores = vector<int>(N);

		for (int i = 0; i < N; i++) {
			cin >> scores[i];
			sum += scores[i];
		}
		average = sum / N;
		
		for (int i = 0; i < N; i++) {
			if (scores[i] > average) cnt++;
		}

		cout << fixed;
		cout.precision(3);
		cout <<(double)cnt / double(N) * 100 << "%" << endl;
	}
}