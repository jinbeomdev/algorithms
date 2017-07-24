//�迭�� �Է¹ް�
//�迭 ó�� ���� ������ ��ȸ
//���࿡ ���� 1�̸� ť�� ����
//��ȸ�� ������ �� ť�� ����� m*n�̸� ����
//��ȸ�� �������� ť�� �ϳ��� ���ϸ鼭 4������ 1�� ����
//������ ���� �� ���� üũ

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int x[] = { 0, 1, -1, 0 }; //i �������� ��, ������, �Ʒ���, ����
int y[] = { -1, 0, 0, 1 }; //j �������� ��, ������, �Ʒ���, ����

int main() {
	vector<vector<int>> box;
	vector<vector<int>> days;
	queue<pair<int, int>> q;
	int M, N;
	int queueSize = 0;
	int Answer = 0;

	cin >> M >> N;

	box = vector<vector<int>>(N, vector<int>(M, 0));
	days = vector<vector<int>>(N, vector<int>(M, -2));

	for (int i = 0; i < box.size(); i++) { //����
		for (int j = 0; j < box[i].size(); j++) { //����
			//cin >> box[i][j];
			scanf("%d", &box[i][j]);

			if (box[i][j] == 1) {
				q.push(make_pair(i, j));
				days[i][j] = 0;
			}
			else if (box[i][j] == -1) {
				days[i][j] = -1;
			}
		}
	}

	queueSize = q.size();

	//ť�� ������� �� ����
	while (!q.empty()) {
		bool swichted = false;
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		queueSize--;

		//i,j�� ������ 4���� �˻�
		for (int k = 0; k < 4; k++) {
			if (i + y[k] >= 0 && j + x[k] >= 0 && i + y[k] < N && j + x[k] < M) {
				if (box[i + y[k]][j + x[k]] == 0) {
					q.push(make_pair(i + y[k], j + x[k]));
					box[i + y[k]][j + x[k]] = 1;
					days[i + y[k]][j + x[k]] = days[i][j] + 1;
				}
				else if (box[i + y[k]][j + x[k]] == -1) {
					days[i + y[k]][j + x[k]] = -1;
				}
			}
		}
	}

	for (int i = 0; i < days.size(); i++) { //����
		for (int j = 0; j < days[i].size(); j++) { //����
		
			if (Answer < days[i][j]) {
					Answer = days[i][j];
			} 
			if(days[i][j] == -2) {
				printf("-1");
				return 0;
			}
		} 
		
	}
	printf("%d", Answer);
	//cout << Answer;
}