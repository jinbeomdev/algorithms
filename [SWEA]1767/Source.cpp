/*
입력
3
7
0 0 1 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 1 0
0 0 0 0 0 0 0
1 1 0 1 0 0 0
0 1 0 0 0 0 0
0 0 0 0 0 0 0
9
0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0
0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1
11
0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1
0 0 0 1 0 0 0 0 1 0 0
0 1 0 1 1 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0

출력
#1 12
#2 10
#3 24
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int const INF = (int)10e6;

int N;
int adj[12][12];
bool visited[12][12];
vector<pair<int, int>> core_locations;

pair<int, int> directions[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int dfs(int core_index, int total_length) {
	int ret = INF;

	if (core_index = core_locations.size() - 1) {
		return total_length;
	}

	for (int i = 0; i < 4; i++) {
		bool is_cross = false;

		int y = core_locations[core_index].first;
		int x = core_locations[core_index].second;

		int length = 0;
			
		while (y == 0 || x == 0 || y == N -1 || x == N - 1) {
			y = y + directions[i].first;
			x = x + directions[i].second;

			length = length + 1;

			if (visited[y][x]) {
				is_cross = true;
				break;
			}

			visited[y][x] = true;
		}

		if (!is_cross) {
			dfs(core_index + 1, total_length + length);
			visited[y][x] = false;
		}

		while (y == core_locations[core_index].first && x == core_locations[core_index].second) {
			y = y + directions[(i + 2) % 4].first;
			x = x + directions[(i + 2) % 4].second;

			visited[y][x] = false;
		}

	}
}

int main() {
	int T, test_case;

	cin >> T;

	for (test_case = 1; test_case <= T; test_case++) {
		cin >> N;

		core_locations.clear();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> adj[i][j];

				if (adj[i][j] == 1) {
					core_locations.push_back({ i, j });
					visited[i][j] = true;
				}
			}
		}

		int result;
		cout << "#" << test_case << " " << result << endl;
	}
}