//배열을 입력받고
//배열 처음 부터 끝까지 순회
//만약에 값이 1이면 큐에 저장
//순회가 끝났을 때 큐의 사이즈가 m*n이면 종료
//순회가 끝났으면 큐를 하나씩 팝하면서 4방향을 1로 변경
//끝나기 전에 일 수를 체크

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int x[] = { 0, 1, -1, 0 }; //i 기준으로 위, 오른쪽, 아래쪽, 왼쪽
int y[] = { -1, 0, 0, 1 }; //j 기준으로 위, 오른쪽, 아래쪽, 왼쪽

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

	for (int i = 0; i < box.size(); i++) { //세로
		for (int j = 0; j < box[i].size(); j++) { //가로
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

	//큐가 비어있을 때 까지
	while (!q.empty()) {
		bool swichted = false;
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		queueSize--;

		//i,j에 인접한 4방향 검색
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

	for (int i = 0; i < days.size(); i++) { //세로
		for (int j = 0; j < days[i].size(); j++) { //가로
		
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