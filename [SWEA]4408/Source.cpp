/*
	4408. 자기 방으로 돌아가기
*/

#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;

int T, N;
queue<pair<int, int>> q;
bool visited[200];

int main() {
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		//init
		scanf("%d", &N);
		memset(visited, false, sizeof(visited));
		while (!q.empty()) {
			q.pop();
		}

		for (int student = 0; student < N; student++) {
			int room[2];

			scanf("%d %d", &room[0], &room[1]);

			for (int i = 0; i < 2; i++) {
				if (!(room[i] % 2)) { //짝수
					room[i] = room[i] / 2 - 1; //복도 인덱스
				} else { //홀수
					room[i] = room[i] / 2; //복도 인덱스
				}
			}

			q.push(make_pair(room[0], room[1]));
		}

		int answer = 0;
		while (!q.empty()) {
			int q_size = q.size();

			for (int i = 0; i < q_size; i++) {
				int room[2];
				room[0] = q.front().first; room[1] = q.front().second;

				bool is_go = true;
				for (int j = room[0]; j <= room[1]; j++) {
					if (visited[j]) {
						is_go = false;
						break;
					}
				}

				if (is_go) {
					for (int j = room[0]; j <= room[1]; j++) {
						visited[j] = true;
					}
					q.pop();
				} else {
					q.pop();
					q.push(make_pair(room[0], room[1]));
				}
			}

			memset(visited, false, sizeof(visited));
			answer++;
		}

		printf("%c%d %d\n",
			'#', test_case, answer);
	}

	return 0;
}