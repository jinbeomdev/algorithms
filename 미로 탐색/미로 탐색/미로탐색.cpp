#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int startX = 0, startY = 0;
int finishX, finishY;
int row[] = {-1, 0, 1, 0};
int column[] = { 0, 1, 0, -1 };

int main() {
	int N, M;
	vector<vector<int>> maze;
	vector<vector<int>> distance;
	vector<vector<int>> visited;
	queue<pair<int, int>> q;

	cin >> N >> M;

	maze = vector<vector<int>>(N, vector<int>(M, -1));
	distance = vector<vector<int>>(N, vector<int>(M, -1));
	visited = vector<vector<int>>(N, vector<int>(M, -1));
	finishX = M - 1; finishY = N - 1;

	//�Է� �ޱ�
	for (int i = 0; i < maze.size(); i++) { //����
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) { //����
			maze[i][j] = s[j] - 48;
		}
	}

	q.push(make_pair(0, 0));
	distance[startY][startX] = 1;

	//ť�� ������� �� ����
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		//������ ����(��, ������, �Ʒ�, ����) Ž��
		for (int k = 0; k < 4; k++) {
			if (i + row[k] >= 0 && i + row[k] < N && j + column[k] >= 0 && j + column[k] < M) {
				//�̷ο��� �̵��� �� �ִ� 'ĭ'�̰�, ������ '�湮'�� ���� '����'�� �Ѵ�.
				if (maze[i + row[k]][j + column[k]] == 1 && visited[i + row[k]][j + column[k]] == -1) {
					q.push(make_pair(i + row[k], j + column[k]));
					distance[i + row[k]][j + column[k]] = distance[i][j] + 1;
					visited[i + row[k]][j + column[k]] = 1;
				}
			}
		} // for end
	} //while end

	cout << distance[finishY][finishX];
}