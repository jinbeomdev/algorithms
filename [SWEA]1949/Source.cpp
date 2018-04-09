/*
[제약 사항]

1. 시간 제한 : 최대 50개 테스트 케이스를 모두 통과하는 데 C/C++/Java 모두 3초

2. 지도의 한 변의 길이 N은 3 이상 8 이하의 정수이다. (3 ≤ N ≤ 8)

3. 최대 공사 가능 깊이 K는 1 이상 5 이하의 정수이다. (1 ≤ K ≤ 5)

4. 지도에 나타나는 지형의 높이는 1 이상 20 이하의 정수이다.

5. 지도에서 가장 높은 봉우리는 최대 5개이다.

6. 지형은 정수 단위로만 깎을 수 있다.

7. 필요한 경우 지형을 깎아 높이를 1보다 작게 만드는 것도 가능하다.
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