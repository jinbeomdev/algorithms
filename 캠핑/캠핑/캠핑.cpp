	#include <vector>
	#include <cstdlib>
	#include <iostream>

	using namespace std;

	// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
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