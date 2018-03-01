//https://www.acmicpc.net/problem/6593

/*
문제
당신은 상범 빌딩에 갇히고 말았다. 여기서 탈출하는 가장 빠른 길은 무엇일까? 상범 빌딩은 각 변의 길이가 1인 정육면체(단위 정육면체)로 이루어져있다. 각 정육면체는 금으로 이루어져 있어 지나갈 수 없거나, 비어있어서 지나갈 수 있게 되어있다. 당신은 각 칸에서 인접한 6개의 칸(동,서,남,북,상,하)으로 1분의 시간을 들여 이동할 수 있다. 즉, 대각선으로 이동하는 것은 불가능하다. 그리고 상범 빌딩의 바깥면도 모두 금으로 막혀있어 출구를 통해서만 탈출할 수 있다.

당신은 상범 빌딩을 탈출할 수 있을까? 만약 그렇다면 얼마나 걸릴까?

입력
입력은 여러 개의 테스트 케이스로 이루어지며, 각 테스트 케이스는 세 개의 정수 L, R, C로 시작한다. L(1 ≤ L ≤ 30)은 상범 빌딩의 층 수이다. R(1 ≤ R ≤ 30)과 C(1 ≤ C ≤ 30)는 상범 빌딩의 한 층의 행과 열의 개수를 나타낸다.

그 다음 각 줄이 C개의 문자로 이루어진 R개의 행이 L번 주어진다. 각 문자는 상범 빌딩의 한 칸을 나타낸다. 금으로 막혀있어 지나갈 수 없는 칸은 '#'으로 표현되고, 비어있는 칸은 '.'으로 표현된다. 당신의 시작 지점은 'S'로 표현되고, 탈출할 수 있는 출구는 'E'로 표현된다. 각 층 사이에는 빈 줄이 있으며, 입력의 끝은 L, R, C가 모두 0으로 표현된다.

출력
각 빌딩에 대해 한 줄씩 답을 출력한다. 만약 당신이 탈출할 수 있다면 다음과 같이 출력한다.

Escaped in x minute(s).
여기서 x는 상범 빌딩을 탈출하는 데에 필요한 최단 시간이다.

만일 탈출이 불가능하다면, 다음과 같이 출력한다.

Trapped!
예제 입력  복사
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
예제 출력  복사
Escaped in 11 minute(s).
Trapped!
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int dfs(int l, int r, int c, int dist);
void bfs();

int iter_l[] = { 0, -1, 1 };
int iter_r[] = { 0, 1, 0, -1 };
int iter_c[] = { 1, 0, -1, 0 };

//!!-------------------------------------------------------------!!/
//!!-------------------------------------------------------------!!/
//variable for dfs
std::pair<int, std::pair<int, int>> start;
std::pair<int, std::pair<int, int>> end;

std::vector<std::vector<std::vector<char>>> adj;
std::vector<std::vector<std::vector<bool>>> visited;
//!!-------------------------------------------------------------!!/
//!!-------------------------------------------------------------!!/

//!!-------------------------------------------------------------!!/
//!!-------------------------------------------------------------!!/
//variable for bfs
std::vector<std::vector<std::vector<int>>> dist;
//!!-------------------------------------------------------------!!/
//!!-------------------------------------------------------------!!/


int L, R, C;

int main() {
	while (true) {
		scanf("%d %d %d", &L, &R, &C);
		
		adj = std::vector<std::vector<std::vector<char>>>(L, std::vector<std::vector<char>>(R, std::vector<char>(C)));
		//visited = std::vector<std::vector<std::vector<bool>>>(L, std::vector<std::vector<bool>>(R, std::vector<bool>(C, false)));
		dist = std::vector<std::vector<std::vector<int>>>(L, std::vector<std::vector<int>>(R, std::vector<int>(C, -1)));

		if (L == 0 && R == 0 && C == 0) {
			break;
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					std::cin >> adj[i][j][k];

					if (adj[i][j][k] == 'S') {
						start = { i, {j, k} };
					}

					if (adj[i][j][k] == 'E') {
						end = { i, {j, k} };
					}
				}
			}
		}
		
		//int ret = dfs(start.first, start.second.first, start.second.second, 0);
		bfs();

		/* dfs
		if(ret > 0)
			printf("Escaped in %d minute(s).", ret);
		else
			printf("Trapped!");
		*/

		/*bfs*/
		if (dist[end.first][end.second.first][end.second.second] > 0)
			printf("Escaped in %d minute(s).\n", dist[end.first][end.second.first][end.second.second]);
		else
			printf("Trapped!\n");
	}
}

//dfs is not suitable to this problem cause we need to find shortest path.
//so I recommend to use bfs
int dfs(int l, int r, int c, int dist)
{
	int ret = -1;

	if (adj[l][r][c] == 'E') {
		return dist;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			int next_l;
			int next_r;
			int next_c;
			if (i == 0) {
				next_l = l;
				next_r = r + iter_r[j];
				next_c = c + iter_c[j];
			}
			else {
				next_l = l + iter_l[i];
				next_c = c;
				next_r = r;
			}

			if (next_l >= 0 && next_l < L &&
				next_r >= 0 && next_r < R &&
				next_c >= 0 && next_c < C &&
				!visited[next_l][next_r][next_c] &&
				adj[next_l][next_r][next_c] != '#') {
				visited[next_l][next_r][next_c] = true;

				ret = std::max(ret, dfs(next_l, next_r, next_c, dist + 1));
			}
		}
	}

	return ret;
}

void bfs()
{
	std::queue<std::pair<int, std::pair<int, int>>> q;

	q.push({ start.first, { start.second.first, start.second.second} });
	dist[start.first][start.second.first][start.second.second] = 0;

	while (!q.empty()) {
		int l = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				int next_l;
				int next_r;
				int next_c;
				if (i == 0) {
					next_l = l;
					next_r = r + iter_r[j];
					next_c = c + iter_c[j];
				}
				else {
					next_l = l + iter_l[i];
					next_c = c;
					next_r = r;
				}

				if (next_l >= 0 && next_l < L &&
					next_r >= 0 && next_r < R &&
					next_c >= 0 && next_c < C &&
					dist[next_l][next_r][next_c] < 0 && //there isn't visited not yet
					adj[next_l][next_r][next_c] != '#') {
					dist[next_l][next_r][next_c] = dist[l][r][c] + 1;

					//if find 'End' location, quit the function. 
					if (end.first == next_l &&
						end.second.first == next_r &&
						end.second.second == next_c) {
						return;
					}

					q.push({ next_l , { next_r, next_c} });
				}
			}
		}
	}
}