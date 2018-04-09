/*
[���� ����]

1. �ð� ���� : �ִ� 50�� �׽�Ʈ ���̽��� ��� ����ϴ� �� C/C++/Java ��� 3��

2. ������ �� ���� ���� N�� 3 �̻� 8 ������ �����̴�. (3 �� N �� 8)

3. �ִ� ���� ���� ���� K�� 1 �̻� 5 ������ �����̴�. (1 �� K �� 5)

4. ������ ��Ÿ���� ������ ���̴� 1 �̻� 20 ������ �����̴�.

5. �������� ���� ���� ���츮�� �ִ� 5���̴�.

6. ������ ���� �����θ� ���� �� �ִ�.

7. �ʿ��� ��� ������ ��� ���̸� 1���� �۰� ����� �͵� �����ϴ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int kMaxN = 8;

const int kIterativeX[] = { 1, 0, -1, 0 };
const int kIterativeY[] = { 0, 1, 0, -1 };

int adj[kMaxN][kMaxN];
bool visited[kMaxN][kMaxN];
bool isCuted = false;
int N, K;

int dfs(int y, int x) {
	int path_length = 0;

	for (int i = 0; i < 4; i++) {
		int next_y = y + kIterativeY[i];
		int next_x = x + kIterativeX[i];

		if (next_y >= 0 && next_y < N &&
				next_x >= 0 && next_x < N &&
				!visited[next_y][next_x]) {

			/* normal case where previous height is higher than next height */
			if (adj[next_y][next_x] < adj[y][x]) {
				visited[next_y][next_x] = true;
				path_length = max(path_length, dfs(next_y, next_x));
				visited[next_y][next_x] = false;
			}

			/* not normal case where previous height is equal or lower than next height
				 but It will be posiible When decreasing the next hieght with K*/
			for (int dig = 1; dig <= K; dig++) {
				if (adj[next_y][next_x] - dig < adj[y][x] &&
					!isCuted) {
					int temp = adj[next_y][next_x];
					adj[next_y][next_x] = adj[next_y][next_x] - dig;
					isCuted = true;
					visited[next_y][next_x] = true;
					path_length = max(path_length, dfs(next_y, next_x));
					isCuted = false;
					visited[next_y][next_x] = false;
					adj[next_y][next_x] = temp;
				}
			}
		}
	}

	return path_length + 1;
}

int main() {
	int test_case_size;

	cin >> test_case_size;

	for (int test_case = 1; test_case <= test_case_size; test_case++) {
		int most_height = 0;
		vector<pair<int, int>> most_height_locations;
		int result = 0;

		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> adj[i][j];

				if (most_height < adj[i][j]) {
					most_height = adj[i][j];
				}
			}
		}

		/* find most height locations */
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (adj[i][j] == most_height) {
					most_height_locations.push_back({ i, j });
				}
			}
		}

		memset(visited, false, sizeof(visited));
		
		for (pair<int, int> most_height_location : most_height_locations) {
			int y = most_height_location.first;
			int x = most_height_location.second;

			visited[y][x] = true;
			result = max(result, dfs(y, x));
			visited[y][x] = false;
		}

		cout << "#" << test_case << " " << result << endl;
	}

	//system("pause");
}