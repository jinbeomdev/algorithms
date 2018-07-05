#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int KNIGHT_MOVEMENT[][8] = {
	{1, 2, 2, 1, -1, -2, -2, -1},
	{-2, -1, 1, 2, 2, 1, -1, -2}
};

int T, L;
int start_x, start_y;
int dest_x, dest_y;
queue<pair<int, int>> q;
vector<vector<bool>> visited;
int answer;

void init() {
	while (!q.empty()) {
		q.pop();
	}

	answer = 0;
}

void debug() {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			if (visited[i][j]) printf("%d ", 1);
			else printf("%d ", 0);
		}
		putchar('\n');
	}
	putchar('\n');
}


int main() {
	scanf("%d", &T);

	for (int test_case = 0; test_case < T; test_case++) {
		init();
		scanf("%d%d%d%d%d", &L, &start_x, &start_y, &dest_x, &dest_y);
		visited = vector<vector<bool>>(L, vector<bool>(L, false));

		q.push(make_pair(start_x, start_y));
		visited[start_y][start_x] = true;

		int is_find = false;
		while (!q.empty()) {
			int q_size = q.size();

			for (int i = 0; i < q_size; i++) {
				int cur_x = q.front().first;
				int cur_y = q.front().second;
				q.pop();

				if (cur_x == dest_x &&
					  cur_y == dest_y) {
					is_find = true;
					break;
				}

				for (int j = 0; j < 8; j++) {
					int next_x = cur_x + KNIGHT_MOVEMENT[0][j];
					int next_y = cur_y + KNIGHT_MOVEMENT[1][j];

					if (next_x < 0 || next_x >= L ||
						  next_y < 0 || next_y >= L) {
						continue;
					}

					if (!visited[next_y][next_x]) {
						visited[next_y][next_x] = true;
						q.push(make_pair(next_x, next_y));
					}
				}
			}

			if (is_find) break;

			answer++;
		}

		printf("%d\n", answer);
	}

	return 0;
}