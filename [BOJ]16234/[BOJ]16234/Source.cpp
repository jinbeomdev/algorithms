#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const int maxSize = 50;

int N, L, R;
int A[maxSize][maxSize] = {};

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int result = 0;

int main() {
	scanf("%d%d%d", &N, &L, &R);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	int cntMove;

	do {
		cntMove = 0;

		bool discoverd[maxSize][maxSize] = {};
		vector<pair<pair<pair<int, int>, int>, int>> moveDay;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//��� ���󿡼� bfs ����
				if (discoverd[i][j]) { //�̹� �湮�� ����� �н�
					continue;
				}

				vector<pair<int, int>> can_go_country;
				queue<pair<int, int>> q;
				can_go_country.push_back({ i, j });
				q.push({ i, j });
				discoverd[i][j] = true;
				int total = A[i][j];

				while (!q.empty()) {
					int here_y = q.front().first;
					int here_x = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) { //4���� ��ȸ
						int next_y = here_y + dy[k];
						int next_x = here_x + dx[k];

						if (next_y < 0 || next_y >= N || //index exception handling
							next_x < 0 || next_x >= N) {
							continue;
						}

						if (discoverd[next_y][next_x]) {
							continue;
						}

						int diff = abs(A[here_y][here_x] - A[next_y][next_x]);

						if (diff < L || diff > R) {
							continue;
						}

						can_go_country.push_back({ next_y, next_x });
						q.push({ next_y, next_x });
						discoverd[next_y][next_x] = true;
						total += A[next_y][next_x];
					}
				}

				//���� ������ ���� ��� �湮����.
				if (can_go_country.size() > 1) {
					for (int i = 0; i < can_go_country.size(); i++) {
						int here_y = can_go_country[i].first;
						int here_x = can_go_country[i].second;
						int size = can_go_country.size();
						moveDay.push_back({ { {here_y, here_x}, total }, size });
					}
				}
			}
		}

		if (moveDay.size() > 0) {
			cntMove++;
			result++;
			for (int i = 0; i < moveDay.size(); i++) {
				int here_y = moveDay[i].first.first.first;
				int here_x = moveDay[i].first.first.second;
				int total = moveDay[i].first.second;
				int size = moveDay[i].second;
				A[here_y][here_x] = total / size;
			}
		}
	} while (cntMove);

	cout << result;
}