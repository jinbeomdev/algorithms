#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;

int R, C;
char map[250][251];
bool discovered[250][250];
int total_sheep;
int total_wolves;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int main() {
	memset(discovered, false, sizeof(discovered));

	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'o') {
				total_sheep++;
			}
			
			if (map[i][j] == 'v') {
				total_wolves++;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (discovered[i][j]) continue;
			if (map[i][j] == '#') continue;

			queue<pii> q;
			q.push(make_pair(i, j));
			discovered[i][j] = true;

			int num_sheep = 0;
			int num_wolves = 0;

			while (!q.empty()) {
				pii here = q.front();
				q.pop();
				int here_y = here.first;
				int here_x = here.second;

				if (map[here_y][here_x] == 'o') num_sheep++;
				if (map[here_y][here_x] == 'v') num_wolves++;

				for (int i = 0; i < 4; i++) {
					int next_y = here_y + dy[i];
					int next_x = here_x + dx[i];

					if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) continue;

					if (map[next_y][next_x] == '#') continue;

					if (discovered[next_y][next_x]) continue;

					discovered[next_y][next_x] = true;
					q.push(make_pair(next_y, next_x));
				}
			}

			if (num_sheep > num_wolves) total_wolves -= num_wolves;

			if (num_sheep <= num_wolves) total_sheep -= num_sheep;
		}
	}

	printf("%d %d\n", total_sheep, total_wolves);
}