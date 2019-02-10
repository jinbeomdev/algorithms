#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX_N = 50;
const int MAX_M = 50;
const int MAX_K = 300;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

struct cell {
	int x, y;
	int hp;
	int time;
	cell(int y_, int x_, int hp_, int time_) : x(x_), y(y_), hp(hp_), time(time_) {}
};

bool comp(cell a, cell b) {
	if (a.time == b.time) {
		return a.hp > b.hp;
	}
	return a.time < b.time;
}

int main() {
	int T, N, M, K;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		bool map[4][350][350] = { 0 };
		vector<cell> active;
		vector<cell> inactive;
		scanf("%d%d%d", &N, &M, &K);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int hp;
				scanf("%d", &hp);
				if (!hp) continue;
				inactive.push_back(cell(i, j, hp, hp));
				map[0][i][j] = true;
			}
		}

		while (K--) {
			sort(inactive.begin(), inactive.end(), comp);
			int ads = 0;
			for (int i = 0; i < inactive.size(); i++) {
				inactive[i].time--;
				if (inactive[i].time == 0) {
					active.push_back(cell(inactive[i].y, inactive[i].x, inactive[i].hp, inactive[i].hp));
					ads++;
				}
			}
			for (int i = 0; i < ads; i++) inactive.erase(inactive.begin());
			for (int i = 0; i < active.size(); i++) {
				if (active[i].hp - active[i].time == 1) {
					for (int j = 0; j < 4; j++) {
						int next_x = active[i].x + dx[j];
						int next_y = active[i].y + dy[j];
						if (next_x >= 0 && next_y >= 0 && !map[0][next_y][next_x]) {
							map[0][next_y][next_x] = true;
						} else if (next_x >= 0 && next_y < 0 && !map[1][-next_y][next_x]) {
							map[1][-next_y][next_x] = true;
						} else if (next_x < 0 && next_y >= 0 && !map[2][next_y][-next_x]) {
							map[2][next_y][-next_x] = true;
						} else if (next_x < 0 && next_y < 0 && !map[3][-next_y][-next_x]) {
							map[3][-next_y][-next_x] = true;
						} else {
							continue;
						}
						inactive.push_back(cell(next_y, next_x, active[i].hp, active[i].hp));
					}
				}
			}
			for (int i = 0; i < active.size(); i++) {
				if (--active[i].time == -1) {
					active.erase(active.begin() + i);
					i--;
				}
			}
		}
		printf("#%d %d\n", test_case, inactive.size() + active.size());
	}
}