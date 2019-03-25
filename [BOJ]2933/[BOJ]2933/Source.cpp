#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;

int R, C;
char map[100][101];
int N;
vector<pii> component;
bool visited[100][100];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void print() {
	puts("");
	for (int i = 0; i < R; i++) {
		printf("%s\n", map[i]);
	}
	puts("");
}

void dfs(int y, int x) {
	visited[y][x] = true;
	component.push_back(make_pair(y, x));

	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_y >= R ||
			next_x < 0 || next_x >= C) continue;

		if (visited[next_y][next_x]) continue;

		if (map[next_y][next_x] == '.') continue;

		dfs(next_y, next_x);
	}
}

int main() {
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", map[i]);
	}
	scanf("%d", &N);
	int turn = 1;
	for (int i = 0; i < N; i++) {
		int qurey;
		scanf("%d", &qurey);
		qurey = R - qurey;
		if (turn == 1) {
			for (int walker = 0; walker < C; walker++) {
				if (map[qurey][walker] == 'x') {
					map[qurey][walker] = '.';
					break;
				}
			}
		} else {
			for (int walker = C - 1; walker >= 0; walker--) {
				if (map[qurey][walker] == 'x') {
					map[qurey][walker] = '.';
					break;
				}
			}
		}
		//print();
		turn *= -1;
		memset(visited, false, sizeof(visited));
		bool is_collision = false;
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (!visited[j][k] && map[j][k] == 'x') {
					component.clear();
					dfs(j, k);
					//start simulate
					sort(component.begin(), component.end());
					if (component.back().first == R - 1) {
						break;
					}
					for (int p = 0; p < component.size(); p++) {
						map[component[p].first][component[p].second] = '.';
					}
					while (true) {
						for (int p = 0; p < component.size(); p++) {
							component[p].first++;
						}
						for (int p = 0; p < component.size(); p++) {
							int y = component[p].first;
							int x = component[p].second;

							if (y < 0 || y >= R || x < 0 || x >= C) {
								is_collision = true;
								break;
							}
							if (map[y][x] == 'x') {
								is_collision = true;
								break;
							}
						}
						if (is_collision) break;
					}
					for (int p = 0; p < component.size(); p++) {
						map[component[p].first - 1][component[p].second] = 'x';
					}
					//print();
				}
				if (is_collision) break;
			}
			if (is_collision) break;
		}
	}
	for (int i = 0; i < R; i++) {
		printf("%s\n", map[i]);
	}
}
