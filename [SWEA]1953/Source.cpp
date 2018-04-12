#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int kMaxMapSize = 50;
const int kTunnelTypeSize = 8; // included zero

int map[kMaxMapSize][kMaxMapSize];
bool visited[kMaxMapSize][kMaxMapSize];
bool final_visited[kMaxMapSize][kMaxMapSize];

int N, M, R, C, L;
int result;

/* ©Л, го, аб, ╩С */
const int iter_x[] = { 1, 0, -1, 0 };
const int iter_y[] = { 0, 1, 0, -1 };


const int kTunnelType[kTunnelTypeSize][5] = {//	/* size, ways where we can go */
	{0},
	{4, 0, 1, 2, 3},
	{2, 1, 3},
	{2, 0, 2},
	{2, 0, 3},
	{2, 0, 1},
	{2, 1, 2},
	{2, 2, 3}
};

bool isConnected(int y, int x, int next_y, int next_x) {
	bool can_go_to_next = false;
	bool can_go_to_previous = false;
	
	for (int i = 1; i <= kTunnelType[map[y][x]][0]; i++) {
		int temp_next_y = y + iter_y[kTunnelType[map[y][x]][i]];
		int temp_next_x = x + iter_x[kTunnelType[map[y][x]][i]];

		if (temp_next_x == next_x && temp_next_y == next_y) {
			can_go_to_next = true;
		}
	}

	for (int i = 1; i <= kTunnelType[map[next_y][next_x]][0]; i++) {
		int temp_previous_y = next_y + iter_y[kTunnelType[map[next_y][next_x]][i]];
		int temp_previous_x = next_x + iter_x[kTunnelType[map[next_y][next_x]][i]];

		if (temp_previous_x == x && temp_previous_y == y) {
			can_go_to_previous = true;
		}
	}

	if (can_go_to_next && can_go_to_previous) return true;
	else return false;
}

void dfs(const int y, const int x, const int distance) {
	if (distance == L) {
		return;
	}

	for (int i = 1; i <= kTunnelType[map[y][x]][0]; i++) {
		int next_y = y + iter_y[kTunnelType[map[y][x]][i]];
		int next_x = x + iter_x[kTunnelType[map[y][x]][i]];

		if (next_y >= 0 && next_y < N &&
				next_x >= 0 && next_x < M &&
				!visited[next_y][next_x] &&
				isConnected(y, x, next_y, next_x)) {
			visited[next_y][next_x] = true;
			dfs(next_y, next_x, distance + 1);
			visited[next_y][next_x] = false;
			final_visited[next_y][next_x] = true;
		}
	}
}

int main() {
	int test_case_size;

	cin >> test_case_size;

	/* better to initialize it only once */
	memset(visited, false, sizeof(visited));
	
	for (int test_case = 1; test_case <= test_case_size; test_case++) {
		/* init */
		memset(final_visited, false, sizeof(final_visited));
		result = 1;
		cin >> N >> M >> R >> C >> L;

		/* get */
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		
		/* solve */
		visited[R][C] = true;
		dfs(R, C, 1);
		visited[R][C] = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (final_visited[i][j]) result++;
			}
		}
		cout << "#" << test_case << " " << result << endl;
	}

	//system("pause");
}