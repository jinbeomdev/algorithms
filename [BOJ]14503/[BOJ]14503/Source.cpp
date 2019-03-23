#include <stdio.h>

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };

const int back_dy[] = { 1, 0, -1, 0 };
const int back_dx[] = { 0, -1, 0, 1 };

int map[50][50];
int N, M;

int robot_y;
int robot_x;
int robot_d;

int main() {
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &robot_y, &robot_x, &robot_d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int answer = 0;
	while (true) {
		//printf("%d %d %d\n", robot_y, robot_x, robot_d);
		map[robot_y][robot_x] = 2;
		answer++;

		bool clean = false;
		for (int i = 0; i < 4; i++) {
			int next_y = robot_y + dy[robot_d];
			int next_x = robot_x + dx[robot_d];

			if (next_y < 0 || next_y >= N ||
				next_x < 0 || next_x >= M) continue;

			if (map[next_y][next_x] == 0) {
				robot_d = (robot_d - 1 == -1) ? 3 : robot_d -1;
				robot_y = next_y;
				robot_x = next_x;
				clean = true;
				break;
			} else {
				robot_d = (robot_d - 1 == -1) ? 3 : robot_d - 1;
			}
		}

		if (!clean) {
			int next_y = robot_y + back_dy[robot_d];
			int next_x = robot_x + back_dx[robot_d];

			if (next_y < 0 || next_y >= N ||
				next_x < 0 || next_x >= M) break;

			if (map[next_y][next_x] == 1) {
				break;
			} else {
				robot_y = next_y;
				robot_x = next_x;
				answer--;
			}
		}
	}

	printf("%d", answer);
}