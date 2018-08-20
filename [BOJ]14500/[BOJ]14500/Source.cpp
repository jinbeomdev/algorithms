#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;

const int d_size = 4;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int map[501][501];
int visited[501][501];

//た で ぬ っ
const int fuck_y[][4] = {
	{0, 1, 1, 2},
	{0, 1, 1, 1},
	{0, 0, 1, 0},
	{0, 1, 1, 2}
};

const int fuck_x[][4] = {
	{ 0, 0, 1, 0 },
	{ 0, -1, 0, 1 },
	{ 0, 1, 1, 2 },
	{ 0, -1, 0, 0 }
};

int dfs(int y, int x, int map[][500], int visited[][500]) {
	int ret = map[y][x];

	int max_value = 0;
	for (int i = 0; i < d_size; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 && next_y >= N ||
			next_x < 0 && next_x >= M) {
			continue;
		}

		if (!visited[y][x]) {
			visited[y][x] = true;
			max_value = max(max_value, dfs(next_y, next_x, map, visited));
			visited[y][x] = false;
		}
	}

	return ret + max_value;
}

int dfs(int y, int x, int depth) {
	int ret = map[y][x];

	if (depth == 4) {
		return ret;
	}

	int max_value = 0;
	for (int i = 0; i < d_size; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_y >= N ||
			next_x < 0 || next_x >= M) {
			continue;
		}

		if (!visited[next_y][next_x]) {
			visited[next_y][next_x] = true;
			max_value = max(max_value, dfs(next_y, next_x, depth + 1));
			visited[next_y][next_x] = false;
		}
	}

	return ret + max_value;
}

int main() {
	//fill(map, map + sizeof(map), 0);
	//fill(visited, visited + sizeof(visited), 0);

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int max_value = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			max_value = max(max_value, dfs(i, j, 1));
			visited[i][j] = false;

			//た で ぬ っ
			bool is_can = true;
			for (int k = 0; k < 4; k++) {
				int value = 0;

				for (int z = 0; z < 4; z++) {
					int next_y = i + fuck_y[k][z];
					int next_x = j + fuck_x[k][z];

					if (next_y < 0 || next_y >= N ||
						next_x < 0 || next_x >= M) {
						break;
					}

					value += map[next_y][next_x];
				}

				max_value = max(max_value, value);
			}
		}
	}

	printf("%d", max_value);
}