//https://www.acmicpc.net/problem/5427

/*
문제
상근이는 빈 공간과 벽으로 이루어진 건물에 갇혀있다. 건물의 일부에는 불이 났고, 상근이는 출구를 향해 뛰고 있다.

매 초마다, 불은 동서남북 방향으로 인접한 빈 공간으로 퍼져나간다. 벽에는 불이 붙지 않는다. 상근이는 동서남북 인접한 칸으로 이동할 수 있으며, 1초가 걸린다. 상근이는 벽을 통과할 수 없고, 불이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다. 상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.

빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개이다.

각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)

다음 h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.

'.': 빈 공간
'#': 벽
'@': 상근이의 시작 위치
'*': 불
각 지도에 @의 개수는 하나이다.

출력
각 테스트 케이스마다 빌딩을 탈출하는데 가장 빠른 시간을 출력한다. 빌딩을 탈출할 수 없는 경우에는 "IMPOSSIBLE"을 출력한다.

예제 입력
5
4 3
####
#*@.
####
7 6
###.###
#*#.#*#
#.....#
#.....#
#..@..#
#######
7 4
###.###
#....*#
#@....#
.######
5 5
.....
.***.
.*@*.
.***.
.....
3 3
###
#@#
###
예제 출력
2
5
IMPOSSIBLE
IMPOSSIBLE
IMPOSSIBLE
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

//clcokwise
const int iter_y[] = {0, 1, 0, -1};
const int iter_x[] = {1, 0, -1, 0};
const int iter_size = 4;

char adj[1000][1000];
int dist[1000][1000];

int main() {
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int w, h;

		//queue for bfs to find shortest path that is connected to exit
		queue<pair<int, int>> q;
		//queue for fire
		queue<pair<int, int>> fire_q;
		pair<int, int> starting_location;

		memset(dist, -1, sizeof(dist));

		cin >> w >> h;

		//get a building map
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> adj[i][j];

				if (adj[i][j] == '@') {
					starting_location = { i, j };
					adj[i][j] = '.';
				}

				if (adj[i][j] == '*') {
					fire_q.push({ i, j });
				}
			}
		}

		//init
		q.push(starting_location);
		dist[starting_location.first][starting_location.second] = 0;

		while (true) {
			if (q.empty()) {
				break;
			}

			//let fire spread to all direction
			int fire_q_size = fire_q.size();

			for (int i = 0; i < fire_q_size; i++) {
				int fire_y = fire_q.front().first;
				int fire_x = fire_q.front().second;
				fire_q.pop();

				for (int j = 0; j < iter_size; j++) {
					int spreaded_fire_y = fire_y + iter_y[j];
					int spreaded_fire_x = fire_x + iter_x[j];

					if (spreaded_fire_y >= 0 && spreaded_fire_y < h &&
						spreaded_fire_x >= 0 && spreaded_fire_x < w &&
						adj[spreaded_fire_y][spreaded_fire_x] == '.') {

						adj[spreaded_fire_y][spreaded_fire_x] = '*';
						fire_q.push({ spreaded_fire_y, spreaded_fire_x });
					}
				}
			}

			int q_size = q.size();
			
			for (int k = 0; k < q_size; k++) {
				//current position
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++) {
					int next_y = y + iter_y[i];
					int next_x = x + iter_x[i];

					if (next_y >= 0 && next_y < h &&
						next_x >= 0 && next_x < w &&
						dist[next_y][next_x] == -1 &&
						adj[next_y][next_x] == '.') {
						q.push({ next_y, next_x });
						dist[next_y][next_x] = dist[y][x] + 1;
					}
				}
			}
		}

		int ret = 10e6;

		for (int i = 0; i < w; i++) {
			if (dist[0][i] != -1) {
				ret = min(ret, dist[0][i]);
			}
		}

		for (int i = 0; i < w; i++) {
			if (dist[h - 1][i] != -1) {
				ret = min(ret, dist[h - 1][i]);
			}
		}

		for (int i = 0; i < h; i++) {
			if (dist[i][0] != -1) {
				ret = min(ret, dist[i][0]);
			}
		}

		for (int i = 0; i < h; i++) {
			if (dist[i][w - 1] != -1) {
				ret = min(ret, dist[i][w - 1]);
			}
		}

		if (ret != 10e6) {
			cout << ret + 1 << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	//system("pause");

	return 0;
}