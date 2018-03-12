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

void compare_two_pair(pair<int, int> &a, pair<int, int> &b) {
	if (a.first < b.first) {
		a = b;
	}

	if (a.first == b.first) {
		a.second = min(b.second, a.second);
	}
}

pair<int, int> dfs(int core_index, int num_connected_core, int total_length) {
	pair<int, int> ret = { -INF, INF };
	pair<int, int> temp;

	if (core_index == core_locations.size()) {
		return { num_connected_core, total_length };
	}

	for (int i = 0; i < 4; i++) {
		bool is_cross = false;

		int y = core_locations[core_index].first;
		int x = core_locations[core_index].second;

		int length = 0;

		while (y != 0 && x != 0 && y != N - 1 && x != N - 1) {
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
			temp = dfs(core_index + 1, num_connected_core + 1, total_length + length);
			compare_two_pair(ret, temp);
		}

		y = core_locations[core_index].first;
		x = core_locations[core_index].second;

		for (int j = 0; j < (is_cross ? length - 1 : length); j++) {
			y = y + directions[i].first;
			x = x + directions[i].second;

			visited[y][x] = false;
		}
	}
	
	temp = dfs(core_index + 1, num_connected_core, total_length);
	compare_two_pair(ret, temp);

	return ret;
}

int main() {
	int T, test_case;

	cin >> T;

	for (test_case = 1; test_case <= T; test_case++) {
		cin >> N;

		core_locations.clear();
		memset(adj, 0, sizeof(adj));
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> adj[i][j];

				if (adj[i][j] == 1) {
					core_locations.push_back({ i, j });
					visited[i][j] = true;
				}
			}
		}

		pair<int, int> result = dfs(0, 0, 0);
		cout << "#" << test_case << " " <<result.second << endl;
	}

	//system("pause");

	return 0;
}