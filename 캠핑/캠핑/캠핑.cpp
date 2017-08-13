	#include <vector>
	#include <cstdlib>
	#include <iostream>

	using namespace std;

	// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
	int solution(int n, vector<vector<int>> data) {
		int answer = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				bool flag = true;

				if (data[i][0] == data[j][0] || data[i][1] == data[j][1]) continue;

				for (int k = 0; k < n; k++) {
					if (data[k][0] > data[i][0] && data[k][1] < data[j][0] &&
						data[k][0] > data[j][0] && data[k][1] < data[j][1])
						flag = false;
				}

				if (flag) {
					cout << "(" << data[i][0] << "," << data[i][1] << ")(" << data[j][0] << "," << data[j][1] << ")" << endl;
					answer++;
				}
			}
		}

		return answer;
	}